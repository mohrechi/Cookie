#include <cstdio>
#include <cstring>
const int MAXN = 1005;
int dp[2][MAXN];
char s1[MAXN], s2[MAXN];
int l1, l2;

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

int main()
{
    while(~scanf("%d%s%d%s", &l1, s1+1, &l2, s2+1))
    {
        for(int i=0;i<=l2;++i)
        {
            dp[0][i] = i;
        }
        for(int i=1;i<=l1;++i)
        {
            int now = i & 1;
            int pre = (i + 1) & 1;
            dp[now][0] = i;
            for(int j=1;j<=l2;++j)
            {
                if(s1[i] == s2[j])
                {
                    dp[now][j] = dp[pre][j-1];
                }
                else
                {
                    dp[now][j] = min(dp[pre][j], dp[now][j-1], dp[pre][j-1]) + 1;
                }
            }
        }
        printf("%d\n", dp[l1&1][l2]);
    }
    return 0;
}
