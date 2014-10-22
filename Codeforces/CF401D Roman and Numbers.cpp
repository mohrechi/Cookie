#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 18;
const int MAXM = 100;

long long n, m;
long long dp[1 << MAXN][MAXM], repeat, f[MAXN];
int base[10], digit[MAXN], num;

int main()
{
    scanf("%I64d%d", &n, &m);
    while (n)
    {
        digit[num++] = n % 10;
        ++base[n % 10];
        n /= 10;
    }
    n = num;
    sort(digit, digit + n);
    f[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        f[i] = f[i - 1] * i;
    }
    repeat = 1;
    for (int i = 0; i < 10; ++i)
    {
        repeat *= f[base[i]];
    }
    for (int i = 0; i < n; ++i)
    {
        if (digit[i])
        {
            dp[1 << i][digit[i] % m] = 1;
        }
    }
    for (int i = 1; i < (1 << n); ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dp[i][j])
            {
                for (int k = 0; k < n; ++k)
                {
                    if ((i & (1 << k)) == 0)
                    {
                        dp[i | (1 << k)][(j * 10 + digit[k]) % m] += dp[i][j];
                    }
                }
            }
        }
    }
    printf("%I64d\n", dp[(1 << n) - 1][0] / repeat);
    return 0;
}
