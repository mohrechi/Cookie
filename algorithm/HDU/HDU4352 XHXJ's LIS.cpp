#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
__int64 dp[19][1<<10][11];
__int64 L, R, K;
__int64 num[20];

void init()
{
    for(int i=0;i<19;++i)
    {
        for(int j=0;j<(1<<10);++j)
        {
            for(int k=0;k<11;++k)
            {
                dp[i][j][k] = -1;
            }
        }
    }
}

__int64 dfs(int pos, int state, int len, bool isTop)
{
    if(pos < 0)
    {
        return len == K;
    }
    if(!isTop && dp[pos][state][K] != -1)
    {
        return dp[pos][state][K];
    }
    __int64 ans = 0;
    int top = isTop?num[pos]:9;
    for(int i=0;i<=top;++i)
    {
        if(state || i)
        {
            if((1 << i) > state)
            {
                ans += dfs(pos - 1, state | (1 << i), len + 1, isTop && (i == top));
            }
            if((1 << i) & state)
            {
                ans += dfs(pos - 1, state, len, isTop && (i == top));
            }
            else
            {
                for(int j=i+1;j<=9;++j)
                {
                    if(state & (1 << j))
                    {
                        ans += dfs(pos - 1, (state | (1 << i)) ^ (1 << j), len, isTop && (i == top));
                        break;
                    }
                }
            }
        }
        else
        {
            ans += dfs(pos - 1, 0, 0, isTop && (i == top));
        }
    }
    if(!isTop && dp[pos][state][K] == -1)
    {
        dp[pos][state][K] = ans;
    }
    return ans;
}

__int64 solve(__int64 x)
{
    if(x == 0)
    {
        return 0;
    }
    int len = 0;
    while(x)
    {
        num[len++] = x % 10;
        x /= 10;
    }
    return dfs(len - 1, 0, 0, true);
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    init();
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%I64d%I64d%I64d", &L, &R, &K);
        printf("Case #%d: %I64d\n", cas, solve(R) - solve(L-1));
    }
    return 0;
}
