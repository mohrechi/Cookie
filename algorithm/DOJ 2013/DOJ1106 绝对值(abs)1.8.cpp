#include <cstdio>
#include <cmath>

int main()
{
    double f;
    while (~scanf("%lf", &f))
    {
        printf("%.2lf\n", fabs(f));
    }
    return 0;
}
