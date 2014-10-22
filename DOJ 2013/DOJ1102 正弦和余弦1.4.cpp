#include <cstdio>
#include <cmath>
const double PI = acos(-1.0);

int main()
{
    double n;
    while (~scanf("%lf", &n))
    {
        printf("%.3lf %.3lf\n", sin(n / 180 * PI), cos(n / 180 * PI));
    }
    return 0;
}
