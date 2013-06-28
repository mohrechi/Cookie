#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double EPS = 1e-10;
const double PI = acos(-1.0);

double dblcmp(double x)
{
    if (fabs(x) < EPS)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

double dblcmp(double x, double y)
{
    return dblcmp(x - y);
}

struct Point
{
    double x, y;
    Point()
    {
        x = y = 0.0;
    }
    Point (double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double length()
    {
        return x * x + y * y;
    }
    Point norm()
    {
        Point p;
        p.x = x / length();
        p.y = y / length();
        return p;
    }
    void output()
    {
        printf("%lf %lf\n", x, y);
    }
};

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

Point operator *(const Point &a, const double &b)
{
    Point c;
    c.x = a.x * b;
    c.y = a.y * b;
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

Point intersect(const Point &u1, const Point &v1, const Point &u2, const Point &v2)
{
    double area1 = fabs(cross(u2, v2, u1));
    double area2 = fabs(cross(u2, v2, v1));
    double area = area1 + area2;
    double len = (v1 - u1).length();
    double len1 = len * area1 / area;
    return u1 + (v1 - u1).norm() * len1;
}

int main()
{
    double L, S;
    while (~scanf("%lf%lf", &L, &S))
    {
        double totalArea = sqrt(3.0) / 4 * L * L;
        if (S > totalArea || S < totalArea * 2 / 3)
        {
            printf("-1\n");
            continue;
        }
        double l = sqrt(3.0) / 3 * L;
        Point A1(l, 0.0);
        Point B1(l * cos(PI * 2.0 / 3.0), l * sin(PI * 2.0 / 3.0));
        double left = 0.0, right = 60.0;
        while (right - left > EPS)
        {
            double mid = (left + right) * 0.5;
            double angle = mid * PI / 180;
            Point A2(l * cos(angle), l * sin(angle));
            Point B2(l * cos(angle + PI * 2.0 / 3.0), l * sin(angle + PI * 2.0 / 3.0));
            Point C2(l * cos(angle - PI * 2.0 / 3.0), l * sin(angle - PI * 2.0 / 3.0));
            Point I1 = intersect(A1, B1, A2, B2);
            Point I2 = intersect(A1, B1, A2, C2);
            double area = totalArea - 3 * fabs(cross(I1, I2, A2)) / 2;
            if (area > S)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        printf("%.9lf\n", left);
    }
    return 0;
}
