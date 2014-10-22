#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 210;
const int MAXM = 510;
const double PI = acos(-1.0);
const double PI2 = PI * 2;

int n, m;
struct Point
{
    int x, y;
    int index;
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
    inline void output() const
    {
        printf("%d %d\n", x, y);
    }
}point[MAXN], total[MAXN + MAXM];
int left[MAXN][MAXN];
int right[MAXN][MAXN];
double queue[(MAXN + MAXM) * 2];
double angle[MAXN + MAXM];

Point operator - (const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

int operator * (const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

bool operator == (const Point &a, const Point &b)
{
    return a.x == b.x && a.y == b.y;
}

int cross(const Point &a, const Point &b, const Point &o)
{
    return (a - o) * (b - o);
}

inline double positiveAtan(const Point &a, const Point &o)
{
    double res = atan2((double)(a.y - o.y), (double)(a.x - o.x));
    if(res < 0.0)
    {
        res += PI2;
    }
    return res;
}

Point centerPoint;
bool operator < (const Point &a, const Point &b)
{
    if(a == centerPoint)
    {
        return true;
    }
    if(b == centerPoint)
    {
        return false;
    }
    return angle[a.index] < angle[b.index];
}

int getDistance(const Point &a, const Point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double getArea(int a, int b, int c)
{
    return cross(point[a], point[b], point[c]) * 0.5;
}

int getAngleNumber(int a, int b, int c)
{
    if(point[c].y < point[b].y && point[a].y >= point[b].y)
    {
        return m - abs(right[b][c]) + abs(right[b][a]);
    }
    return abs(right[b][a] - right[b][c]);
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;++i)
        {
            point[i].input();
            total[i] = point[i];
            total[i].index = i;
        }
        for(int i=0;i<m;++i)
        {
            total[i + n].input();
            total[i + n].index = i + n;
        }
        for(int i=0;i<n;++i)
        {
            centerPoint = point[i];
            for(int j=0;j<n+m;++j)
            {
                angle[total[j].index] = positiveAtan(total[j], centerPoint);
            }
            sort(total, total + n + m);
            int front = 0, rear = 0;
            int cnt = 0, start = n + m;
            for(int j=0;j<n+m;++j)
            {
                if(angle[total[j].index] > PI)
                {
                    start = j;
                    break;
                }
                if(total[j].index >= n)
                {
                    queue[rear++] = angle[total[j].index];
                    ++ cnt;
                }
            }
            for(int j=start;j<n+m;++j)
            {
                double t = angle[total[j].index];
                if(t < PI)
                {
                    t += PI2;
                }
                if(cnt)
                {
                    while(t - queue[front] > PI && front < rear)
                    {
                        ++ front;
                        -- cnt;
                    }
                }
                if(total[j].index < n)
                {
                    left[total[j].index][i] = cnt;
                }
                else
                {
                    queue[rear++] = t;
                    ++ cnt;
                }
            }
            for(int j=0;j<start;++j)
            {
                double t = angle[total[j].index];
                if(t < PI)
                {
                    t += PI2;
                }
                if(cnt)
                {
                    while(t - queue[front] > PI && front < rear)
                    {
                        ++ front;
                        -- cnt;
                    }
                }
                if(total[j].index < n)
                {
                    left[total[j].index][i] = cnt;
                }
                else
                {
                    queue[rear++] = t;
                    ++ cnt;
                }
            }
            cnt = 0;
            for(int j=0;j<n+m;++j)
            {
                if(total[j].index < n)
                {
                    right[i][total[j].index] = cnt;
                }
                else
                {
                    ++ cnt;
                }
            }
        }
        #ifndef ONLINE_JUDGE
        printf("Left: \n");
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                printf("%d ", left[i][j]);
            }
            printf("\n");
        }
        printf("Right: \n");
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                printf("%d ", right[i][j]);
            }
            printf("\n");
        }
        #endif
        bool flag = false;
        double ans = 1e100;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                for(int k=j+1;k<n;++k)
                {
                    double area = getArea(i, j, k);
                    int a, b, c;
                    if(area < 0.0)
                    {
                        area = - area;
                        a = k, b = j, c = i;
                    }
                    else
                    {
                        a = i, b = j, c = k;
                    }
                    int num = m - (left[a][b] + left[b][c] + left[c][a] - getAngleNumber(a, b, c) - getAngleNumber(b, c, a) - getAngleNumber(c, a, b));
                    if(num > 0)
                    {
                        flag = true;
                        ans = min(ans, area / num);
                    }
                }
            }
        }
        printf("Case #%d: ", cas);
        if(flag)
        {
            printf("%.6lf\n", ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
