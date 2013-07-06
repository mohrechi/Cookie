#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXM = 55;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
long long a[MAXN][MAXM];
long long dp[MAXN][MAXM];
long long sum[MAXM];
long long maxL[MAXM];
long long maxR[MAXM];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%lld", &a[i][j]);
            }
        }
        long long ans = -INF;
        maxR[m + 1] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                sum[j] = sum[j - 1] + a[i][j];
                maxL[j] = max(maxL[j - 1] + a[i][j], a[i][j]);
            }
            for (int j = m; j >= 1; --j)
            {
                maxR[j] = max(maxR[j + 1] + a[i][j], a[i][j]);
            }
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = -INF;
                for (int k = 1; k <= m; ++k)
                {
                    if (j == k)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + maxL[j] + maxR[j] - a[i][k]);
                    }
                    else if (j > k)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + maxR[j] + maxL[k] + sum[j - 1] - sum[k]);
                    }
                    else
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][k] + maxL[j] + maxR[k] + sum[k - 1] - sum[j]);
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
