#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
} p[4];

Point operator +(const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

Point operator -(const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

int operator *(const Point &a, const Point &b)
{
    return a.x * b.x + a.y * b.y;
}

int operator ^(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

int cross(const Point &a, const Point &b, const Point &o)
{
    return (a - o) ^ (b - o);
}

int main()
{
    for (int i = 0; i < 4; ++i)
    {
        p[i].input();
    }
    int ans = 0;
    for (int i = 0; i < 4; ++i)
    {
        Point p1 = p[i];
        Point p2 = p[(i + 2) % 4];
        Point p3 = p[(i + 1) % 4];
        Point p4 = p[(i + 3) % 4];
        if (abs(cross(p1, p2, p3)) == abs(cross(p1, p2, p4)))
        {
            if ((p2 - p1) * (p4 - p3) == 0)
            {
                ++ans;
            }
        }
        p1 = p[i] + p[(i + 1) % 4];
        p2 = p[(i + 2) % 4] + p[(i + 3) % 4];
        p3 = p[(i + 1) % 4] + p[(i + 2) % 4];
        p4 = p[(i + 3) % 4] + p[i];
        if (abs(cross(p1, p2, p3)) == abs(cross(p1, p2, p4)))
        {
            if ((p2 - p1) * (p4 - p3) == 0)
            {
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
