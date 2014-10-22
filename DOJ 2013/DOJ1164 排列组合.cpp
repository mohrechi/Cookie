#include <cstdio>
const int MAXN = 31;

long long a[MAXN][MAXN];

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        a[i][0] = 1;
    }
    for (int i = 1; i < MAXN; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
}

int main()
{
    int n, m;
    init();
    while (~scanf("%d%d", &n, &m))
    {
        printf("%lld\n", a[n][m]);
    }
    return 0;
}
