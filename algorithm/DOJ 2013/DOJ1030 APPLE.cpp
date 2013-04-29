#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000;
const int MAXM = 30;

int dp[MAXN * 2][MAXM * 2];

bool judge(int n, int m, int a)
{
    long long num = 1;
    for (int i = 0; i < m; ++i)
    {
        num *= n;
        if (num >= a)
        {
            return true;
        }
    }
    return false;
}

int get(int n, int m, int a)
{
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    if (judge(n, m, a))
    {
        return dp[n][m] = 2;
    }
    if (n == 1 && m >= MAXM + MAXM / 2)
    {
        return dp[n][m] = 1;
    }
    if (get(n + 1, m, a) == 0 || get(n, m + 1, a) == 0)
    {
        return dp[n][m] = 2;
    }
    if (get(n + 1, m, a) == 2 && get(n, m + 1, a) == 2)
    {
        return dp[n][m] = 0;
    }
    return dp[n][m] = 1;
}

int main()
{
    int N, M, A;
    while (~scanf("%d%d%d", &N, &M, &A))
    {
        memset(dp, -1, sizeof(dp));
        int ans;
        if (judge(N, M, A))
        {
            ans = 0;
        }
        else
        {
            ans = get(N, M, A);
        }
        switch (ans)
        {
        case 0:
            printf("lose\n");
            break;
        case 1:
            printf("draw\n");
            break;
        case 2:
            printf("win\n");
            break;
        }
    }
    return 0;
}
