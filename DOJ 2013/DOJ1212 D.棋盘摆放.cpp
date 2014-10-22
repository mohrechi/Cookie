#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20;
const int MOD = 1e9 + 7;

int n, a, board[MAXN];
int dp[MAXN][1 << MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            board[i] = 0;
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &a);
                if (a)
                {
                    board[i] |= (1 << j);
                }
            }
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i)
        {
            if ((board[0] & (1 << i)) == 0)
            {
                dp[0][1 << i] = 1;
            }
        }
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = 0; j < (1 << n); ++j)
            {
                if (dp[i][j])
                {
                    for (int k = 0; k < n; ++k)
                    {
                        if (((j | board[i + 1]) & (1 << k)) == 0)
                        {
                            int mask = j | (1 << k);
                            dp[i + 1][mask] += dp[i][j];
                            if (dp[i + 1][mask] > MOD)
                            {
                                dp[i + 1][mask] -= MOD;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", dp[n - 1][(1 << n) - 1]);
    }
    return 0;
}
