#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 205;

struct Point
{
    double x, y;
    inline void input()
    {
        scanf("%lf%lf", &x, &y);
    }
} point[MAXN];
int n;

double cross(const Point &a, const Point &b, const Point &o)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double getArea()
{
    double ans = 0.0;
    for(int i=2;i<n;++i)
    {
        ans += fabs(cross(point[i], point[i - 1], point[0]));
    }
    return ans * 0.5;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            point[i].input();
        }
        printf("%.6lf\n", getArea());
    }
    return 0;
}
