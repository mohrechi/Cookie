#include <cstdio>

int main()
{
    double a, b, c;
    while (~scanf("%lf%lf%lf", &a, &b, &c))
    {
        printf("%.3lf\n", (a + b + c) / 3);
    }
    return 0;
}
