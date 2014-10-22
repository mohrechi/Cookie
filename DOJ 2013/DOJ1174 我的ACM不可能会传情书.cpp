#include <cstdio>
#include <cstring>
const int MAXN = 1005;

char s[MAXN][MAXN];
char ans[MAXN * MAXN];

int main()
{
    int T, n, m, a;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        while (getchar() != '\n');
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                s[i][j] = getchar();
            }
            while (getchar() != '\n');
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &a);
                ans[a] = s[i][j];
            }
        }
        ans[n * m + 1] = 0;
        puts(ans + 1);
    }
    return 0;
}
