#include <cstdio>
const int MAXN = 50 + 5;
const int MOD = 1e9 + 7;

int n;
int c[MAXN][MAXN];

int main()
{
    c[0][0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    while (~scanf("%d", &n))
    {
        printf("%d\n", c[n][n >> 1]);
    }
    return 0;
}
