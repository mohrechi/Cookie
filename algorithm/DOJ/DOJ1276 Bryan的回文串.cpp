#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

char s[MAXN];
int dp[2][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        for(int i=n;i>=1;--i)
        {
            int now = i & 1;
            int pre = (i + 1) & 1;
            for(int j=i+1;j<=n;++j)
            {
                if(s[i] == s[j])
                {
                    dp[now][j] = dp[pre][j-1];
                }
                else
                {
                    dp[now][j] = min(dp[pre][j], dp[now][j-1]) + 1;
                }
            }
        }
        if(dp[1][n] <= 1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
