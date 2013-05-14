#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const double eps = 1e-8;

int dblcmp(double x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

int dblcmp(double x, double y)
{
    return dblcmp(x - y);
}

int n;
struct Point
{
    double x, y;
    inline void input()
    {
        scanf("%lf%lf", &x, &y);
    }
} points[MAXN], plane;

struct Circle
{
    Point center;
    double radius;
};

double dist(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Point mid(const Point &a, const Point &b)
{
    Point c;
    c.x = (a.x + b.x) * 0.5;
    c.y = (a.y + b.y) * 0.5;
    return c;
}

bool isLine(const Point &a, const Point &b, const Point &c)
{
    return (int)((a.y - c.y) * (b.x - c.x)) == (int)((b.y - c.y) * (a.x - c.x));
}

Circle getCircleLine(const Point &a, const Point &b, const Point &c)
{
    Circle circle;
    double la = dist(a, b);
    double lb = dist(b, c);
    double lc = dist(c, a);
    if (la >= lb && la >= lc)
    {
        circle.center = mid(a, b);
        circle.radius = la * 0.5;
    }
    else if (lb >= la && lb >= lc)
    {
        circle.center = mid(b, c);
        circle.radius = lb * 0.5;
    }
    else
    {
        circle.center = mid(c, a);
        circle.radius = lc * 0.5;
    }
    return circle;
}

struct Line
{
    double a, b, c;
    inline void output()
    {
        printf("%.2lf x + %.2lf y + %.2lf = 0\n", a, b, c);
    }
};

Line getLine(const Point &a, const Point &b)
{
    Line line;
    line.a = b.y - a.y;
    line.b = a.x - b.x;
    line.c = b.x * a.y - a.x * b.y;
    return line;
}

Line getPerpendicular(const Line &line, const Point &point)
{
    Line per;
    per.a = line.b;
    per.b = -line.a;
    per.c = line.a * point.y - line.b * point.x;
    return per;
}

Point getInsect(const Line &a ,const Line &b)
{
    Point point;
    point.x = (b.b * a.c - a.b * b.c) / (b.a * a.b - a.a * b.b);
    point.y = (a.a * b.c - b.a * a.c) / (b.a * a.b - a.a * b.b);
    return point;
}

Circle getCircleTriangle(const Point &a, const Point &b, const Point &c)
{
    Circle circle;
    Line line1 = getPerpendicular(getLine(a, c), mid(a, c));
    Line line2 = getPerpendicular(getLine(b, c), mid(b, c));
    circle.center = getInsect(line1, line2);
    circle.radius = dist(circle.center, a);
    return circle;
}

Circle getCircle(const Point &a, const Point &b, const Point &c)
{
    if (isLine(a, b, c))
    {
        return getCircleLine(a, b, c);
    }
    return getCircleTriangle(a, b, c);
}

bool isInside(const Circle &circle, const Point &point)
{
    return dblcmp(dist(point, circle.center), circle.radius) <= 0;
}

void getMinimumRadius()
{
    Circle circle;
    circle.center = points[0];
    circle.radius = 0;
    for (int i = 1; i < n; ++i)
    {
        if (!isInside(circle, points[i]))
        {
            circle.center = points[i];
            circle.radius = 0;
            for (int j = 0; j < i; ++j)
            {
                if (!isInside(circle, points[j]))
                {
                    circle.center.x = (points[i].x + points[j].x) * 0.5;
                    circle.center.y = (points[i].y + points[j].y) * 0.5;
                    circle.radius = dist(points[j], circle.center);
                    for (int k = 0; k < j; ++k)
                    {
                        if (!isInside(circle, points[k]))
                        {
                            circle = getCircle(points[i], points[j], points[k]);
                        }
                    }
                }
            }
        }
    }
    printf("(%.1lf,%.1lf).\n%.1lf\n", circle.center.x, circle.center.y, circle.radius);
}

int main()
{
    int a;
    while (~scanf("%d%d%d", &a, &a, &n))
    {
        for (int i = 0; i < n; ++i)
        {
            points[i].input();
        }
        getMinimumRadius();
    }
    return 0;
}
