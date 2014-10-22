#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n;
struct Point
{
    double x, y;
    inline void input()
    {
        scanf("%lf%lf", &x, &y);
    }
} point[MAXN];

Point operator -(const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

double operator ^(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

double cross(const Point &a, const Point &b, const Point &o)
{
    return (a - o) ^ (b - o);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        point[i].input();
    }
    double ans = 0.0;
    for (int i = 2; i < n; ++i)
    {
        ans += cross(point[i], point[i - 1], point[0]);
    }
    printf("%.2lf\n", fabs(ans) * 0.5);
    return 0;
}
