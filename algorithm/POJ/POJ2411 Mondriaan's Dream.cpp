#include <cstdio>
#include <cstring>
long long dp[2][1<<12];
int h, w;

void dfs(int row, int index, int status, long long number)
{
    if(index == w)
    {
        dp[row][status] += number;
        return;
    }
    if(index <= w - 2 && (status & (1 << index)) == 0 && (status & (1 << (index + 1))) == 0)
    {
        dfs(row, index + 2, status | (1 << index) | (1 << (index + 1)), number);
    }
    dfs(row, index + 1, status, number);
}

int main()
{
    int pre, now;
    while(scanf("%d%d",&h,&w), h || w)
    {
        memset(dp, 0, sizeof(dp));
        dfs(0, 0, 0, 1);
        for(int i=1;i<h;++i)
        {
            pre = (i + 1) & 1;
            now = i & 1;
            memset(dp[now], 0, sizeof(dp[now]));
            for(int j=0;j<1<<w;++j)
            {
                if(dp[pre][j])
                {
                    dfs(now, 0, (~j) & ((1<<w) - 1), dp[pre][j]);
                }
            }
        }
        printf("%lld\n", dp[(h-1) & 1][(1<<w) - 1]);
    }
    return 0;
}
