#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 210;
const int MAXNN = MAXN * MAXN;
const int MOD = 1000000007;
const double eps = 1e-8;
const double PI = acos(-1.0);
const double PI2 = PI * 2;

struct Point
{
    double x, y;
    __int64 index;
    double angle;

    inline void input()
    {
        scanf("%lf%lf", &x, &y);
    }
}point[MAXN], temp[MAXN];
int n;
bool visit[MAXNN];
__int64 fib[MAXNN];
__int64 fk[MAXNN];
int num[MAXN][MAXN];
int left[MAXN][MAXN];
int right[MAXN][MAXN];

inline Point operator - (const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

inline double operator * (const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

inline bool operator == (const Point &a, const Point &b)
{
    return a.x == b.x && a.y == b.y;
}

inline int cross(const Point &a, const Point &b, const Point &o)
{
    return (a - o) * (b - o) > 0.0 ? 1 : -1;
}

inline int cross(const int &a, const int &b, const int &o)
{
    return cross(point[a], point[b], point[o]);
}

inline double positiveAtan(const Point &a, const Point &o)
{
    double res = atan2(a.y - o.y, a.x - o.x);
    if(res < 0.0)
    {
        res += PI2;
    }
    return res;
}

bool operator < (const Point &a, const Point &b)
{
    return a.angle < b.angle;
}

int getAngleNumber(int a, int b, int c)
{
    if(point[c].y < point[b].y && point[a].y >= point[b].y)
    {
        return n - abs(right[b][c] - right[b][a] + 2) + 3;
    }
    return abs(right[b][a] - right[b][c]) + 2;
}

int getTriangleNumber(int a, int b, int c)
{
    return n - left[a][b] - left[b][c] - left[c][a] + getAngleNumber(a, b, c) + getAngleNumber(b, c, a) + getAngleNumber(c, a, b) - 6;
}

__int64 pow_mod(__int64 x, __int64 y)
{
    if(x == 0)
    {
        return 0;
    }
    if(x == 1 || y == 0)
    {
        return 1;
    }
    __int64 d = x;
    __int64 res = 1;
    for(int i=0;(1LL<<i)<=y;++i)
    {
        if(y & (1LL<<i))
        {
            res = (res * d) % MOD;
        }
        d = (d * d) % MOD;
    }
    return res;
}

__int64 solve(int x)
{
    if(visit[x])
    {
        return fk[x];
    }
    visit[x] = true;
    fib[0] = x;
    fib[1] = x;
    for(int i=2;i<=x;++i)
    {
        fib[i] = (fib[i-1] * fib[i-2]) % MOD;
    }
    return fk[x] = fib[x] + 1;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;++i)
        {
            point[i].input();
            temp[i] = point[i];
            temp[i].index = i;
        }
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    if(k != i && k != j)
                    {
                        if(cross(k, j, i) < 0)
                        {
                            ++ left[i][j];
                        }
                        else if(cross(k, i, j) < 0)
                        {
                            ++ left[j][i];
                        }
                    }
                }
            }
            for(int j=0;j<n;++j)
            {
                if(temp[j].index == i)
                {
                    temp[j].angle = - 1e100;
                }
                else
                {
                    temp[j].angle = positiveAtan(temp[j], point[i]);
                }
            }
            sort(temp, temp + n);
            int cnt = 0;
            for(int j=0;j<n;++j)
            {
                right[i][temp[j].index] = ++ cnt;
            }
        }
        memset(num, 0 ,sizeof(num));
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                for(int k=0;k<n;++k)
                {
                    if(k == i || k == j)
                    {
                        continue;
                    }
                    if(cross(point[k], point[j], point[i]) < 0)
                    {
                        num[i][j] += getAngleNumber(j, k, i) - getTriangleNumber(i, j, k);
                    }
                }
            }
        }
        __int64 ans = 1;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                ans = (ans * solve(num[i][j])) % MOD;
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
