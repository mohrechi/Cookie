#include <cstdio>

int main()
{
    double a, b, c, d;
    while (~scanf("%lf%lf%lf%lf", &a, &b, &c, &d))
    {
        double x = (b - a) * (d - c) / b / d;
        printf("%.6lf\n", a / b / (1 - x));
    }
    return 0;
}
