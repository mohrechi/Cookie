#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

int dp[MAXN];

int main()
{
    int n;
    dp[0] = 0;
    for (int i = 1; i < MAXN; ++i)
    {
        if (i >= 4)
        {
            dp[i] = max(dp[i], dp[i - 4] + 1);
            if (i >= 8)
            {
                dp[i] = max(dp[i], dp[i - 8] + 3);
                if (i >= 16)
                {
                    dp[i] = max(dp[i], dp[i - 16] + 9);
                }
            }
        }
    }
    while (~scanf("%d", &n))
    {
        printf("%d\n", dp[n]);
    }
    return 0;
}
