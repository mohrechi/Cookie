#include <cstdio>

int main()
{
    int t, n, a, sum;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        sum = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            sum += a;
        }
        printf("%.3lf\n", 1.0 * sum / n);
    }
    return 0;
}
