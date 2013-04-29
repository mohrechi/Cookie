#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
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

struct TransfromMatrix
{
    double data[4][4];
    TransfromMatrix()
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                data[i][j] = 0.0;
            }
            data[i][i] = 1.0;
        }
    }
    inline void output()
    {
        printf("Matrix: \n");
        for (int i = 0; i < 4; ++i)
        {
            printf("\t");
            for (int j = 0; j < 4; ++j)
            {
                printf("%.2lf ", data[i][j]);
            }
            printf("\n");
        }
    }
};

TransfromMatrix operator *(const TransfromMatrix &a, const TransfromMatrix &b)
{
    TransfromMatrix c;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            c.data[i][j] = 0;
            for (int k = 0; k < 4; ++k)
            {
                c.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return c;
}

int n;
struct Point
{
    double x, y, z;
    inline void input()
    {
        scanf("%lf%lf%lf", &x, &y, &z);
    }
    inline void output()
    {
        printf("(%.2lf, %.2lf, %.2lf)\n", x, y, z);
    }
} points[MAXN], plane;

struct Circle
{
    Point center;
    double radius;
    inline void output()
    {
        printf("Center (%.2lf %.2lf) Radius %.2lf\n", center.x, center.y, radius);
    }
};

Point operator * (const Point &a, const TransfromMatrix &b)
{
    Point c;
    c.x = a.x * b.data[0][0] + a.y * b.data[1][0] + a.z * b.data[2][0] + b.data[3][0];
    c.y = a.x * b.data[0][1] + a.y * b.data[1][1] + a.z * b.data[2][1] + b.data[3][1];
    c.z = a.x * b.data[0][2] + a.y * b.data[1][2] + a.z * b.data[2][2] + b.data[3][2];
    return c;
}

TransfromMatrix getWorldTransfromMatrix()
{
    TransfromMatrix world;
    double a = plane.x;
    double b = plane.y;
    double c = plane.z;
    double base = sqrt(b * b + c * c);
    if (dblcmp(base) > 0)
    {
        TransfromMatrix xTransform;
        double cosValue = c / base;
        double sinValue = b / base;
        xTransform.data[1][1] = cosValue;
        xTransform.data[1][2] = sinValue;
        xTransform.data[2][1] = -sinValue;
        xTransform.data[2][2] = cosValue;
        world = world * xTransform;
        plane = plane * xTransform;
    }
    a = plane.x;
    b = plane.y;
    c = plane.z;
    base = sqrt(a * a + c * c);
    if (dblcmp(base) > 0)
    {
        TransfromMatrix yTransform;
        double cosValue = c / base;
        double sinValue = - a / base;
        yTransform.data[0][0] = cosValue;
        yTransform.data[0][2] = -sinValue;
        yTransform.data[2][0] = sinValue;
        yTransform.data[2][2] = cosValue;
        world = world * yTransform;
        plane = plane * yTransform;
    }
    return world;
}

void transfrom()
{
    TransfromMatrix world = getWorldTransfromMatrix();
    for (int i = 0; i < n; ++i)
    {
        points[i] = points[i] * world;
    }
}

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
        printf("a: %.2lf b: %.2lf c: %.2lf\n", a, b, c);
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

double getMinimumRadius()
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
    return circle.radius;
}

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            points[i].input();
        }
        plane.input();
        transfrom();
        printf("%.2lf\n", getMinimumRadius());
    }
    return 0;
}
