#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 200;
const double eps = 1e-12;

int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

struct Point
{
    double x, y;
    inline void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    inline void output()
    {
        printf("%.2lf %.2lf\n", x, y);
    }
    bool operator < (const Point &point) const
    {
        if(y == point.y)
        {
            return x < point.x;
        }
        return y < point.y;
    }
}key[MAXN], poly[MAXN];
int n, polyNumber;

double operator * (const Point &x, const Point &y)
{
    return x.x * y.y - x.y * y.x;
}

Point operator - (const Point &x, const Point &y)
{
    Point r;
    r.x = x.x - y.x;
    r.y = x.y - y.y;
    return r;
}

bool operator == (const Point &a, const Point &b)
{
    return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
}

struct Line
{
    Point a, b;
    double ang;
}line[MAXN], stack[MAXN];
int lineNumber, stackTop;

bool operator < (const Line &x, const Line &y)
{
    if(fabs(x.ang - y.ang) < eps)
    {
        return (y.b - x.a) * (x.b - y.a) > eps;
    }
    return x.ang < y.ang;
}

Point operator * (const Line &x, const Line &y)
{
    double a1 = (y.b - x.a) * (y.a - x.a);
    double a2 = (y.a - x.b) * (y.b - x.b);
    Point r;
    r.x = (x.a.x * a2 + x.b.x * a1) / (a1 + a2);
    r.y = (x.a.y * a2 + x.b.y * a1) / (a1 + a2);
    return r;
}

double cross(Point &a, Point &b, Point &o)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool judgeOut(const Line &x, const Point &p)
{
    return (p - x.a) * (x.b - x.a) > eps;
}

bool isParellel(const Line &x, const Line &y)
{
    return fabs((x.b - x.a) * (y.b - y.a)) < eps;
}

double getArea(Point p[], int n)
{
    double ans = 0.0;
    for(int i=2;i<n;++i)
    {
        ans += fabs(cross(p[i], p[i-1], p[0]));
    }
    return ans * 0.5;
}

void halfPlane()
{
    polyNumber = 0;
    sort(line, line + lineNumber);
    stackTop = 1;
    int bottom = 0, tmp = 1;
    for(int i=1;i<lineNumber;++i)
    {
        if(line[i].ang - line[i-1].ang > eps)
        {
            line[tmp++] = line[i];
        }
    }
    lineNumber = tmp;
    stack[0] = line[0], stack[1] = line[1];
    for(int i=2;i<lineNumber;++i)
    {
        if(isParellel(stack[stackTop], stack[stackTop-1]) || isParellel(stack[bottom], stack[bottom+1]))
        {
            return;
        }
        while(bottom < stackTop && judgeOut(line[i], stack[stackTop] * stack[stackTop - 1]))
        {
            -- stackTop;
        }
        while(bottom < stackTop && judgeOut(line[i], stack[bottom] * stack[bottom + 1]))
        {
            ++ bottom;
        }
        stack[++stackTop] = line[i];
    }
    while(bottom < stackTop && judgeOut(stack[bottom], stack[stackTop] * stack[stackTop - 1]))
    {
        -- stackTop;
    }
    while(bottom < stackTop && judgeOut(stack[stackTop], stack[bottom] * stack[bottom + 1]))
    {
        ++ bottom;
    }
    if(stackTop <= bottom + 1)
    {
        return;
    }
    stack[++stackTop] = stack[bottom];
    for(int i=bottom;i<stackTop;++i)
    {
        poly[polyNumber ++] = stack[i] * stack[i+1];
    }
    int k = 1;
    for(int i=1;i<polyNumber;++i)
    {
        if(dblcmp(poly[i].x - poly[i-1].x) != 0 || dblcmp(poly[i].y - poly[i-1].y) != 0)
        {
            poly[k++] = poly[i];
        }
    }
    polyNumber = k;
}

double getIntegral(Point p0, Point p1, Point p2)
{
    double k1 = (p1.y - p0.y) / (p1.x - p0.x);
    double k2 = (p2.y - p0.y) / (p2.x - p0.x);
    double res = (k1 - k2) * (p0.x - p1.x) * (p0.x - p1.x) * (p0.x + p1.x * 2 + p0.y * 3 - k1 * p0.x + k1 * p1.x - k2 * p0.x + k2 * p1.x - 6) / 6;
    return fabs(res);
}

void addLine(double x0, double y0, double x1, double y1)
{
    line[lineNumber].a.x = x0;
    line[lineNumber].a.y = y0;
    line[lineNumber].b.x = x1;
    line[lineNumber].b.y = y1;
    line[lineNumber].ang = atan2(y1 - y0, x1 - x0);
    ++ lineNumber;
}

double calc(int index)
{
    lineNumber = 0;
    addLine(0.0, 0.0, 1.0, 0.0);
    addLine(1.0, 0.0, 1.0, 1.0);
    addLine(1.0, 1.0, 0.0, 1.0);
    addLine(0.0, 1.0, 0.0, 0.0);
    Point mid, lp;
    for(int i=0;i<n;++i)
    {
        if(i != index)
        {
            mid.x = (key[i].x + key[index].x) * 0.5;
            mid.y = (key[i].y + key[index].y) * 0.5;
            if(dblcmp(key[i].y - key[index].y) == 0)
            {
                lp.x = mid.x;
                lp.y = mid.y + 1.0;
            }
            else
            {
                double k = - (key[i].x - key[index].x) / (key[i].y - key[index].y);
                lp.x = mid.x + 1.0;
                lp.y = mid.y + k;
            }
            if(cross(lp, mid, key[index]) > 0)
            {
                swap(mid, lp);
            }
            addLine(mid.x, mid.y, lp.x, lp.y);
        }
    }
    halfPlane();
    double ans = 0.0;
    Point p[3], pc;
    Line l[2];
    for(int i=2;i<polyNumber;++i)
    {
        p[0] = poly[i];
        p[1] = poly[i-1];
        p[2] = poly[0];
        for(int j=0;j<3;++j)
        {
            for(int k=j+1;k<3;++k)
            {
                if(p[j].x > p[k].x)
                {
                    swap(p[j], p[k]);
                }
            }
        }
        if(dblcmp(p[0].x - p[1].x) == 0)
        {
            if(p[0].y > p[1].y)
            {
                ans += getIntegral(p[2], p[0], p[1]);
            }
            else
            {
                ans += getIntegral(p[2], p[1], p[0]);
            }
        }
        else if(dblcmp(p[2].x - p[1].x) == 0)
        {
            if(p[1].y > p[2].y)
            {
                ans += getIntegral(p[0], p[1], p[2]);
            }
            else
            {
                ans += getIntegral(p[0], p[2], p[1]);
            }
        }
        else
        {
            l[0].a = p[1];
            l[0].b = p[1];
            l[0].b.y -= 1.0;
            l[1].a = p[0];
            l[1].b = p[2];
            pc = l[0] * l[1];
            if(p[1].y > pc.y)
            {
                ans += getIntegral(p[0], p[1], pc);
                ans += getIntegral(p[2], p[1], pc);
            }
            else
            {
                ans += getIntegral(p[0], pc, p[1]);
                ans += getIntegral(p[2], pc, p[1]);
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            key[i].input();
        }
        printf("Case #%d:\n", cas);
        for(int i=0;i<n;++i)
        {
            printf("%.6lf\n", calc(i));
        }
    }
    return 0;
}
