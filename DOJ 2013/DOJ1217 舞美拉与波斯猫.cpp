#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

int n, t;
long long dp[MAXN][2];

int main()
{
    int T, a;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &t);
        ++t;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            if (i <= t)
            {
                dp[i][1] = a;
            }
            else
            {
                dp[i][1] = a + max(dp[i - t][0], dp[i - t][1]);
            }
        }
        printf("%lld\n", max(dp[n][0], dp[n][1]));
    }
    return 0;
}
