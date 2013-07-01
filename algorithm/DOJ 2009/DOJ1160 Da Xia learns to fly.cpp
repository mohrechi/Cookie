#include <cstdio>
#include <cstring>

static const int MAXN  = 100010;
static const int MOD = 1000000007;

long long dp[MAXN][2];

int main()
{
    int n;
        memset(dp, 0, sizeof(dp));
        long long sumo = 0;
        long long sume = 1;
        dp[0][0] = 1;
        for(int i=1;i<=100000;++i)
        {
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
            if(i>=3) dp[i][0] += dp[i-3][0] + dp[i-3][1];
            if(i>1)
                if(i&1)
                    dp[i][1] += sumo;
                else
                    dp[i][1] += sume;
            if(i&1)
                sumo += dp[i][0];
            else
                sume += dp[i][0];
            sumo %= MOD;
            sume %= MOD;
            dp[i][0] %= MOD;
            dp[i][1] %= MOD;
        }
    while(~scanf("%d", &n))
    {
        printf("%lld\n", (dp[n][0]+dp[n][1])%MOD);
    }
    return 0;
}
