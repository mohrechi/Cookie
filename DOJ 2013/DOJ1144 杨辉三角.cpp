#include <cstdio>
#include <cstring>
const int MAXN = 100;

long long a[MAXN][MAXN];

int main()
{
    int n;
    a[0][0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        for (int j = 0; j < MAXN; ++j)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if (j)
                {
                    putchar(' ');
                }
                printf("%lld", a[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
