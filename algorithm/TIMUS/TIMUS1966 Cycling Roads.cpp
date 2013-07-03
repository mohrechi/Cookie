#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 205;

int n, m;
int father[MAXN];

struct Point
{
    long long x, y;
    inline void input()
    {
        cin >> x >> y;
    }
} statues[MAXN], roads[MAXN];

Point operator -(const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

long long operator ^(const Point &a, const Point &b)
{
    return a.x * b.y - a.y * b.x;
}

int cross(const Point &a, const Point &b, const Point &o)
{
    long long res = (a - o) ^ (b - o);
    if (res > 0)
    {
        res = 1;
    }
    else if (res < 0)
    {
        res = -1;
    }
    return res;
}

bool isIntersect(const Point &a, const Point &b, const Point &c, const Point &d)
{
    return max(a.x, b.x) >= min(c.x, d.x) &&
            max(c.x, d.x) >= min(a.x, b.x) &&
            max(a.y, b.y) >= min(c.y, d.y) &&
            max(c.y, d.y) >= min(a.y, b.y) &&
            cross(a, b, c) * cross(a, b, d) <= 0 && cross(c, d, a) * cross(c, d, b) <= 0;
}

bool isOn(const Point &a, const Point &b, const Point &c)
{
    return c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) &&
            c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y) &&
            (c.x - a.x) * (b.y - a.y) == (c.y - a.y) * (b.x - a.x);
}

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if (x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void combine(int x, int y)
{
    x = find(x);
    y = find(y);
    father[x] = y;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            statues[i].input();
        }
        init();
        for (int i = 1; i <= m; ++i)
        {
            roads[i].input();
            combine(roads[i].x, roads[i].y);
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j == roads[i].x)
                {
                    continue;
                }
                if (j == roads[i].y)
                {
                    continue;
                }
                if (isOn(statues[roads[i].x], statues[roads[i].y], statues[j]))
                {
                    combine(roads[i].x, j);
                    combine(roads[i].y, j);
                }
            }
            for (int j = i + 1; j <= m; ++j)
            {
                if (isIntersect(statues[roads[i].x], statues[roads[i].y], statues[roads[j].x], statues[roads[j].y]))
                {
                    combine(roads[i].x, roads[j].x);
                    combine(roads[i].x, roads[j].y);
                    combine(roads[i].y, roads[j].x);
                    combine(roads[i].y, roads[j].y);
                }
            }
        }
        bool flag = true;
        for (int i = 2; i <= n; ++i)
        {
            if (find(i) != find(1))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
