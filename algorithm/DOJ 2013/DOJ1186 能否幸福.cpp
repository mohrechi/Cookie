#include <cstdio>

int main()
{
    long long a, b, c, d;
    while (~scanf("%lld%lld%lld%lld", &a, &b, &c, &d))
    {
        long long ans[10], ansNum = 0;
        for (long long x = -1000; x <= 1000; ++x)
        {
            if (a * x * x * x + b * x * x + c * x + d == 0)
            {
                ans[ansNum++] = x;
            }
        }
        printf("%lld\n", ansNum);
        for (int i = 0; i < ansNum; ++i)
        {
            if (i)
            {
                putchar(' ');
            }
            printf("%lld", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
