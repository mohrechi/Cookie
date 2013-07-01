#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 10010;
const double PI = acos(-1.0);
const double eps = 1e-8;

inline int dblcmp(const double &x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

struct Point
{
    double x, y, z;
    inline void input()
    {
        double latitude, longitude;
        scanf("%lf%lf", &latitude, &longitude);
        double theta = (latitude + 90.0) * PI / 180.0;
        double phi = longitude * PI / 180.0;
        x = sin(theta) * cos(phi);
        y = sin(theta) * sin(phi);
        z = cos(theta);
    }
}alien[MAXN], general;
int n, m;
double r, k, v0;

inline Point operator - (const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

inline double operator * (const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline double pow2(const double &x)
{
    return x * x;
}

struct Vector
{
    Point u, v;
    inline double length() const
    {
        return sqrt(pow2(u.x - v.x) + pow2(u.y - v.y) + pow2(u.z - v.z));
    }
};

inline double operator * (const Vector &a, const Vector &b)
{
    return (a.v - a.u) * (b.v - b.u);
}

inline double getAngle(const Vector &a, const Vector &b)
{
    return acos(fabs(a * b) / a.length() / b.length());
}

int main()
{
    int a, b;
    Vector v1, v2;
    v2.u.x = 0.0;
    v2.u.y = 0.0;
    v2.u.z = 0.0;
    double alpha;
    while(~scanf("%d%d%lf", &n, &m, &r))
    {
        for(int i=0;i<n;++i)
        {
            alien[i].input();
        }
        while(m--)
        {
            scanf("%d%d", &a, &b);
            general.input();
            scanf("%lf%lf", &k, &v0);
            v1.u = alien[a];
            v1.v = alien[b];
            v2.v = general;
            alpha = getAngle(v1, v2);
            if(dblcmp(alpha) == 0)
            {
                printf("0.000\n");
            }
            else if(dblcmp(k) == 0 || dblcmp(v0) == 0 || dblcmp(alpha - PI * 0.5) == 0)
            {
                printf("God Bless Him!\n");
            }
            else
            {
                double ans = log((1 + sin(alpha)) / (1 - sin(alpha))) / k / v0 * 0.5;
                printf("%.3lf\n", fabs(ans));
            }
        }
        printf("\n");
    }
    return 0;
}
