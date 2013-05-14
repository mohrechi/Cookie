#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1505;
const double PI = acos(-1.0);
const double PI2 = PI * 2;
const double eps = 1e-8;

//#define DEBUG

int n;
struct Point
{
    int index;
    double x, y;
    inline void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    inline void output() const
    {
        printf("%.2lf %.2lf\n", x, y);
    }
} points[MAXN], sortedPoints[MAXN], centerPoint;
int left[MAXN][MAXN];
int right[MAXN][MAXN];
double angle[MAXN];
double queue[MAXN * 2];

inline int dblcmp(const double &x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

bool operator ==(const Point &a, const Point &b)
{
    return (int)a.x == (int)b.x && (int)a.y == (int)b.y;
}

Point operator +(const Point &a, const Point &b)
{
    Point c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

Point operator -(const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

double operator *(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

double operator ^(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

double cross(const Point &a, const Point &b, const Point &o)
{
    return (a - o) ^ (b - o);
}

bool operator <(const Point &a, const Point &b)
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

inline double positiveAtan(const Point &a, const Point &o)
{
    double res = atan2((double)(a.y - o.y), (double)(a.x - o.x));
    if(res < 0.0)
    {
        res += PI2;
    }
    return res;
}

long long C(int n, int m)
{
    long long res = 1;
    for (int i = 0; i < m; ++i)
    {
        res *= n - i;
    }
    for (int i = 1; i <= m; ++i)
    {
        res /= i;
    }
    return res;
}

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            points[i].index = i;
            points[i].input();
            sortedPoints[i] = points[i];
        }
        long long sum = C(n, 3) * 3;
        for (int i = 0; i < n; ++i)
        {
            centerPoint = points[i];
            for (int j = 0; j < n; ++j)
            {
                angle[sortedPoints[j].index] = positiveAtan(sortedPoints[j], centerPoint);
            }
            sort(sortedPoints, sortedPoints + n);
            int k = 1;
            int num = 0;
            #ifdef DEBUG
            printf("Sorted Points ");
            centerPoint.output();
            for (int j = 0; j < n; ++j)
            {
                printf("%.3lf - ", angle[sortedPoints[j].index]);
                sortedPoints[j].output();
            }
            #endif
            for (int j = 1; j < n; ++j)
            {
                //sortedPoints[j].output();
                //sortedPoints[k].output();
                //printf("dbl %lf\n", cross(sortedPoints[k], sortedPoints[j], sortedPoints[i]));
                while (dblcmp(cross(sortedPoints[k], sortedPoints[j], centerPoint)) <= 0 && num < n - 1)
                {
                    ++k;
                    ++num;
                    if (k >= n)
                    {
                        k = 1;
                    }
                }
                if (num >= 3)
                {
                    sum += C(num - 1, 2);
                }
                --num;
            }
            #ifdef DEBUG
            printf("Sum: %lld\n", sum);
            #endif
        }
        sum -= 2 * C(n, 4);
        printf("%lf\n", (double)sum / C(n, 3));
    }
    return 0;
}
