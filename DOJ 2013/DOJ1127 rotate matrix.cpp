#include <cstdio>
const int MAXN = 15;

int main()
{
    int n, m, a[MAXN][MAXN];
    while (scanf("%d%d", &n, &m), n || m)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j)
                {
                    putchar(' ');
                }
                printf("%d", a[n - j - 1][i]);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
