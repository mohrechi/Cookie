#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

static const int MAXN = 20050;
static const double EPS = 1e-8;

inline int dblcmp(double x)
{
    if(fabs(x) < EPS)
    {
        return 0;
    }
    return x>0?1:-1;
}

inline int dblcmp(double x, double y)
{
    return dblcmp(x-y);
}

struct Point
{
    double x,y;

    Point()
    {
        x = 0, y = 0;
    }

    Point(double x0, double y0)
    {
        x = x0, y = y0;
    }

    Point operator - (const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }

    double operator * (const Point &p) const
    {
        return x * p.y - y * p.x;
    }

    bool operator == (const Point &p) const
    {
        return x == p.x && y == p.y;
    }
}points[MAXN];

int pointNumber;

struct Line
{
    Point s,t;
    double angle;

    Point operator * (const Line &line) const
    {
        double t1, t2, r1, r2;
        t1 = (line.t - s) * (line.s - s);
        t2 = (line.s - t) * (line.t - t);
        r1 = (s.x * t2 + t.x * t1) / (t1 + t2);
        r2 = (s.y * t2 + t.y * t1) / (t1 + t2);
        return Point(r1, r2);
    }

    bool operator < (const Line &line) const
    {
        if(dblcmp(line.angle, angle) == 0)
        {
            return dblcmp((line.t - line.s) * (t - line.s)) >= 0;
        }
        return angle < line.angle;
    }
}lines[MAXN], queue[MAXN];

int lineNumber;

inline bool isParallel(const Line &line1, const Line &line2)
{
    return dblcmp((line1.t - line1.s) * (line2.t - line2.s)) == 0;
}

inline bool isOutside(const Line &line, const Point &point)
{
    return dblcmp((point - line.s) * (line.t - line.s)) > 0;
}

double getArea(Point *pointArray, int pointNumber)
{
    if(pointNumber < 3)
    {
        return 0.0;
    }
    double area = 0.0;
    for(int i=1;i<pointNumber;++i)
    {
        area += pointArray[i] * pointArray[i+1];
    }
    area += pointArray[pointNumber] * pointArray[1];
    return fabs(area * 0.5);
}

void addLine(Point s, Point t)
{
    ++lineNumber;
    lines[lineNumber].s = s;
    lines[lineNumber].t = t;
    Point temp = t - s;
    lines[lineNumber].angle = atan2(temp.y, temp.x);
}

void initialHalfPanel()
{
    lineNumber = 0;
    addLine(Point(0, 0), Point(10000, 0));
    addLine(Point(10000, 0), Point(10000, 10000));
    addLine(Point(10000, 10000), Point(0, 10000));
    addLine(Point(0, 10000), Point(0, 0));
}

void halfPanel()
{
    sort(lines + 1, lines + lineNumber + 1);
    int count = 1;
    for(int i=2;i<=lineNumber;++i)
    {
        if(dblcmp(lines[i].angle - lines[i-1].angle) != 0)
        {
            lines[++count] = lines[i];
        }
    }
    int left = 0, right = 1;
    queue[left] = lines[1];
    queue[right] = lines[2];
    for(int i=3;i<=count;++i)
    {
        while(left < right && isOutside(lines[i], queue[right] * queue[right - 1]))
        {
            -- right;
        }
        while(left < right && isOutside(lines[i], queue[left] * queue[left + 1]))
        {
            ++ left;
        }
        queue[++right] = lines[i];
    }
    while(left < right && isOutside(queue[left], queue[right] * queue[right - 1]))
    {
        -- right;
    }
    while(left < right && isOutside(queue[right], queue[left] * queue[left + 1]))
    {
        ++ left;
    }
    pointNumber = 0;
    for(int i=left;i<right;++i)
    {
        points[++pointNumber] = queue[i] * queue[i+1];
    }
    points[++pointNumber] = queue[left] * queue[right];
    pointNumber = unique(points + 1, points + pointNumber + 1) - points - 1;
}

int main(int argc, char *argv[])
{
    int n;
    double x1,y1,x2,y2;
    initialHalfPanel();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        addLine(Point(x1, y1), Point(x2, y2));
    }
    halfPanel();
    printf("%.1lf\n", getArea(points, pointNumber));
    return 0;
}
