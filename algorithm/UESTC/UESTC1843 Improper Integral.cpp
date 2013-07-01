#include <cmath>
#include <cstdio>

double phi(double quantile)
{
    return 0.5 + 0.5 * erf(quantile / sqrt(2));
}

int main()
{
    int T;
    double x;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf", &x);
        printf("%.5lf\n", phi(x));
    }
    return 0;
}
