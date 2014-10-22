#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;

int n, p[MAXN];
int dp[MAXN][MAXN];

int dfs(int a, int b)
{
    if (a > b)
    {
        return 0;
    }
    if (dp[a][b] != -1)
    {
        return dp[a][b];
    }
    dp[a][b] = 0;
    for (int i = a + 1; i <= b; ++i)
    {
        if (a + 1 <= i - 1)
        {
            if (((i - 1) - (a + 1)) % 2 == 0)
            {
                continue;
            }
        }
        if (i + 1 <= b)
        {
            if (((b) - (i + 1)) % 2 == 0)
            {
                continue;
            }
        }
        dp[a][b] = max(dp[a][b], dfs(a + 1, i - 1) + dfs(i + 1, b) + (p[a] == p[i]));
    }
    return dp[a][b];
}

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &p[i]);
        }
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(0, n - 1));
    }
    return 0;
}
