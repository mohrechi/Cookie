#include <cstdio>
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN][5];
char s[MAXN];

int main()
{
    int n;
    scanf("%s", s);
    switch (s[0])
    {
    case '?':
        dp[0][0] = dp[0][2] = dp[0][4] = 1;
        break;
    case '*':
        dp[0][4] = 1;
        break;
    case '0':
        dp[0][0] = 1;
        break;
    case '1':
        dp[0][2] = 1;
        break;
    }
    int i;
    for (i = 1; s[i]; ++i)
    {
        switch (s[i])
        {
        case '?':
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = dp[i - 1][4];
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][3] = dp[i - 1][4];
            dp[i][4] = ((dp[i - 1][2] + dp[i - 1][3]) % MOD + dp[i - 1][4]) % MOD;
            break;
        case '*':
            dp[i][4] = ((dp[i - 1][2] + dp[i - 1][3]) % MOD + dp[i - 1][4]) % MOD;
            break;
        case '0':
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            break;
        case '1':
            dp[i][1] = dp[i - 1][4];
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            break;
        case '2':
            dp[i][3] = dp[i - 1][4];
            break;
        }
    }
    --i;
    printf("%d\n", ((dp[i][0] + dp[i][1]) % MOD + dp[i][4]) % MOD);
    return 0;
}
