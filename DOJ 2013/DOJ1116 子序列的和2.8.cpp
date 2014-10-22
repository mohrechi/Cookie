#include <cstdio>

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        double ans = 0.0;
        for (int i = n; i <= m; ++i)
        {
            ans += 1.0 / (1.0 * i * i);
        }
        printf("%.5lf\n", ans);
    }
    return 0;
}
