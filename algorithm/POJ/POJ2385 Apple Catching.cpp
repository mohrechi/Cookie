#include <cstdio>
#include <cstring>
static const int MAXN = 1005;
static const int MAXM = 35;
int dp[MAXN][MAXM][2];
int n, m, a[MAXN];

inline int max(int x, int y)
{
    return x>y?x:y;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=n;++i)
        {
            dp[i][0][0] = dp[i-1][0][0] + (a[i] == 1);
            dp[i][0][1] = dp[i-1][0][1] + (a[i] == 2);
            for(int j=1;j<=m;++j)
            {
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j-1][1]) + (a[i] == 1);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]) + (a[i] == 2);
            }
        }
        printf("%d\n", max(dp[n][m][0], dp[n][m][1]));
    }
    return 0;
}
