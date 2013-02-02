#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1010;
const int MAXK = MAXN * 2;
const int MOD = 100000007;

__int64 dp[MAXN][MAXK][2];

int main()
{
    memset(dp, 0, sizeof(dp));
    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    for(int i=2;i<=1000;++i)
    {
        for(int j=1;j<=2000;++j)
        {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j-1][0] + dp[i-1][j][1] * 2 + dp[i-1][j-1][1];
            dp[i][j][1] = dp[i-1][j-1][1] * 2 + dp[i-1][j][1] + dp[i-1][j-1][0] * 2;
            if(j > 1)
            {
                dp[i][j][1] += dp[i-1][j-2][0] + dp[i-1][j-2][1];
            }
            dp[i][j][0] %= MOD;
            dp[i][j][1] %= MOD;
        }
    }
    int t, n, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        printf("%I64d\n", (dp[n][k][0] + dp[n][k][1]) % MOD);
    }
    return 0;
}
