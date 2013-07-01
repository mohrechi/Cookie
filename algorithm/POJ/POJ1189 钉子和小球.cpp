#include <cstdio>
#include <cstring>
static const int MAXN = 55;
long long dp[MAXN][MAXN];
long long n, m;
char board[MAXN][MAXN];

long long gcd(long long a, long long b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    while(~scanf("%lld%lld", &n, &m))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                scanf("%s", &board[i][j]);
            }
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = ((long long)1) << n;
        for(int i=1;i<=n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(board[i-1][j] == '*')
                {
                    dp[i][j] += dp[i-1][j] >> 1;
                    dp[i][j+1] += dp[i-1][j] >> 1;
                }
                else
                {
                    dp[i+1][j+1] += dp[i-1][j];
                }
            }
        }
        long long g = gcd(dp[n][m], dp[0][0]);
        printf("%lld%/%lld\n", dp[n][m] / g, dp[0][0] / g);
    }
    return 0;
}
