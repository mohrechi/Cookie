#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;
const int MOD = 1e9 + 7;

int n;
long long dp[MAXN];

int main()
{
    dp[0] = dp[1] = 1;
    for (int i = 2; i < MAXN; ++i)
    {
        dp[i] = ((i - 1) * dp[i - 1] % MOD + (i - 2) * dp[i - 2] % MOD) % MOD;
    }
    while (~scanf("%d", &n))
    {
        printf("%lld\n", dp[n]);
    }
    return 0;
}
