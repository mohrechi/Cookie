#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10;
const int MAXM = 1005;

int n, m;
char nail[MAXN << 1];
int dp[MAXM][1 << MAXN];

void printBit(int x)
{
    for (int i = n - 1; i >= 0; --i)
    {
        if (x & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf(" ");
}

int main()
{
    while (~scanf("%d", &n))
    {
        scanf("%s", nail);
        scanf("%d", &m);
        int nail1 = 0, nail2 = 0;
        int full = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nail[i] == '*')
            {
                nail1 |= (1 << i);
                nail2 |= (1 << (n - i - 1));
            }
            full |= (1 << i);
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 0; j < (1 << n); ++j)
            {
                if (dp[i - 1][j] != 0x3f3f3f3f)
                {
                    if (!(j & (1 << (n - 1))))
                    {
                        int next = (j << 1) + 1;
                        dp[i][next] = min(dp[i][next], dp[i - 1][j]);
                        dp[i][next & ~nail1] = min(dp[i][next & ~nail1], dp[i - 1][j] + 1);
                        dp[i][next & ~nail2] = min(dp[i][next & ~nail2], dp[i - 1][j] + 1);
                        int temp1 = nail1;
                        int temp2 = nail2;
                        for (int k = 1; k < n; ++k)
                        {
                            temp1 = (temp1 << 1) & full;
                            temp2 = (temp2 << 1) & full;
                            dp[i][next & ~temp1] = min(dp[i][next & ~temp1], dp[i - 1][j] + 1);
                            dp[i][next & ~temp2] = min(dp[i][next & ~temp2], dp[i - 1][j] + 1);
                        }
                        temp1 = nail1;
                        temp2 = nail2;
                        for (int k = 1; k < n; ++k)
                        {
                            temp1 = (temp1 >> 1) & full;
                            temp2 = (temp2 >> 1) & full;
                            dp[i][next & ~temp1] = min(dp[i][next & ~temp1], dp[i - 1][j] + 1);
                            dp[i][next & ~temp2] = min(dp[i][next & ~temp2], dp[i - 1][j] + 1);
                        }
                    }
                }
            }
        }
        if (dp[m][0] == 0x3f3f3f3f)
        {
            dp[m][0] = -1;
        }
        printf("%d\n", dp[m][0]);
    }
    return 0;
}
