#include <cmath>
#include <cstdio>

struct Point
{
    int x, y;
    inline int input()
    {
        return ~scanf("%d%d", &x, &y);
    }
} point[3];

double dist(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    while (point[0].input())
    {
        point[1].input();
        point[2].input();
        double a = dist(point[0], point[1]);
        double b = dist(point[1], point[2]);
        double c = dist(point[2], point[0]);
        double p = (a + b + c) * 0.5;
        double s = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("%.3lf\n", s);
    }
    return 0;
}
