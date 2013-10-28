#include <cstdio>
#include <cmath>
const double EPS = 1e-8;

double area(double a, double b, double c)
{
    double p = (a + b + c) * 0.5;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int dblcmp(double x)
{
    if (fabs(x) < EPS)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

int main()
{
    double a, b, c;
    while (~scanf("%lf%lf%lf", &a, &b, &c))
    {
        if (dblcmp(a + b - c) <= 0 ||
            dblcmp(b + c - a) <= 0 ||
            dblcmp(a + c - b) <= 0)
        {
            printf("0.000\n");
        }
        else
        {
            printf("%.3lf\n", area(a, b, c));
        }
    }
    return 0;
}
