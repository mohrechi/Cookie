#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n, x[MAXN];
long long dp[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &x[i]);
        }
        long long ans = 0;
        for (int i = 0; i <= n; ++i)
        {
            dp[i] = 0;
            for (int j = 0; j < i; ++j)
            {
                if (j + 1 == i)
                {
                    dp[i] = max(dp[i], dp[j] + x[j]);
                }
                else
                {
                    dp[i] = max(dp[i], dp[j] + (long long)abs(x[j] - x[i - 1]) * (i - j));
                }
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
