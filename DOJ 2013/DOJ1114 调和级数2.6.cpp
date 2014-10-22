#include <cstdio>

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        double ans = 0.0;
        for (int i = 1; i <= n; ++i)
        {
            ans += 1.0 / i;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}
