#include <cstdio>
#include <cstring>
const int MAXN = 5005;

int n;
char s[MAXN];
int dp[2][MAXN];

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    while(~scanf("%d", &n))
    {
        scanf("%s", s + 1);
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
        printf("%d\n", dp[1][n]);
    }
}
