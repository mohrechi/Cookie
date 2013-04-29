#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
const int MOD = 1000000007;

int C[MAXN][MAXN];

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        C[i][0] = 1;
    }
    for (int i = 1; i < MAXN; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

int main()
{
    init();
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        if (2 * k >= n || 2 * k >= m)
        {
            printf("0\n");
        }
        else
        {
            printf("%lld\n", ((long long)C[n - 1][k << 1] * C[m - 1][k << 1]) % MOD);
        }
    }
    return 0;
}
