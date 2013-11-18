#include <cstdio>

int main()
{
    int T, n, m;
    long long sum, max;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        sum = 0;
        max = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &m);
            sum += m;
            if (m > max)
            {
                max = m;
            }
        }
        if (max > sum - max + 1)
        {
            puts("No");
        }
        else
        {
            puts("Yes");
        }
    }
    return 0;
}
