#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 4005;
const int MAXK = 805;

int n, k;
int a[MAXN][MAXN];
char s[MAXN * 2];
int dp[MAXN][MAXN];

int sum(int l, int r)
{
    return a[r][r] - a[l - 1][r] - a[r][l - 1] + a[l - 1][l - 1];
}

void calc(int x, int l, int r, int optL, int optR)
{
    int mid = (l + r) >> 1;
    int pos = optL;
    dp[x][mid] = 0x3f3f3f3f;
    for (int i = optL; i < min(optR + 1, mid); ++i)
    {
        if (dp[x - 1][i] + sum(i + 1, mid) < dp[x][mid])
        {
            dp[x][mid] = dp[x - 1][i] + sum(i + 1, mid);
            pos = i;
        }
    }
    if (l == r)
    {
        return;
    }
    calc(x, l, mid, optL, pos);
    calc(x, mid + 1, r, pos, optR);
}

int main()
{
    while (~scanf("%d%d\n", &n, &k))
    {
        for (int i = 1; i <= n; ++i)
        {
            gets(s);
            for (int j = 1; j <= n; ++j)
            {
                a[i][j] = (s[(j - 1) << 1]) - '0';
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            }
        }
        int ans = 0;
        if (k < n)
        {
            for (int i = 1; i <= n; ++i)
            {
                dp[1][i] = sum(1, i);
            }
            for (int i = 2; i <= k; ++i)
            {
                calc(i, 1, n + 1, 1, n);
            }
            ans = dp[k][n];
        }
        printf("%d\n", ans >> 1);
    }
    return 0;
}
