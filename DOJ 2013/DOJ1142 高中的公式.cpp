#include <cmath>
#include <cstdio>
const double EPS = 1e-8;

double area(double a, double b, double c)
{
    double p = (a + b + c) * 0.5;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double innerRadius(double a, double b, double c)
{
    return area(a, b, c) * 2 / (a + b + c);
}

double outerRadius(double a, double b, double c)
{
    if (b * b + c * c < a * a) return a * 0.5;
    if (a * a + c * c < b * b) return b * 0.5;
    if (a * a + b * b < c * c) return c * 0.5;
    return a * b * c / (area(a, b, c) * 4);
}

int main()
{
    int a, b, c, r;
    while (~scanf("%d%d%d%d", &a, &b, &c, &r))
    {
        if (r + EPS < innerRadius(a, b, c) ||
            r - EPS > outerRadius(a, b, c))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
