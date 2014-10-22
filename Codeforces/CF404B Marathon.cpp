#include <cstdio>

int main()
{
    double a, d;
    int n;
    while (~scanf("%lf%lf%d", &a, &d, &n))
    {
        double l = 0.0;
        while (n--)
        {
            l += d;
            l -= (int)(l / (a * 4)) * (a * 4);
            if (l < a)
            {
                printf("%.6f %.6f\n", l, 0.0);
            }
            else if (l < a * 2)
            {
                printf("%.6f %.6f\n", a, l - a);
            }
            else if (l < a * 3)
            {
                printf("%.6f %.6f\n", a - l + a * 2, a);
            }
            else
            {
                printf("%.6f %.6f\n", 0.0, a - l + a * 3);
            }
        }
    }
    return 0;
}
