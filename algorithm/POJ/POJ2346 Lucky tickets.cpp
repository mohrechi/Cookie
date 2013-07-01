#include <cstdio>
#include <cstring>

int dp[6][50];
int ans[6];

int main()
{
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<=9;++i)
    {
        dp[1][i] = 1;
    }
    for(int i=2;i<=5;++i)
    {
        for(int j=0;j<=45;++j)
        {
            for(int k=0;k<10;++k)
            {
                if(j >= k)
                {
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }
    }
    memset(ans, 0, sizeof(ans));
    for(int i=1;i<=5;++i)
    {
        for(int j=0;j<=45;++j)
        {
            ans[i] += dp[i][j] * dp[i][j];
        }
    }
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d\n", ans[n>>1]);
    }
    return 0;
}
