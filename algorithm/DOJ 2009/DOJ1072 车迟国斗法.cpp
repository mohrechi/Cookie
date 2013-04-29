#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 150;

int n;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int square(int a, int b)
{
    return (a - b) * (a - b);
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &b[i]);
        }
        dp[1][1] = square(a[1], b[1]);
        for(int i=2;i<=n;++i)
        {
            dp[1][i] = dp[1][i - 1] + square(a[1], b[i]);
            dp[i][1] = dp[i - 1][1] + square(a[i], b[1]);
        }
        for(int i=2;i<=n;++i)
        {
            for(int j=2;j<=n;++j)
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + square(a[i], b[j]);
            }
        }
        printf("%d\n", dp[n][n]);
    }
    return 0;
}
