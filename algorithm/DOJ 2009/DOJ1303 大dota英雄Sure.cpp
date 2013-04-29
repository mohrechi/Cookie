#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 11;
const int MAXM = 1005;
const int MAXL = 1005;

int n, m, mn;
int hit[MAXN][MAXM];
int l, monster;
int dp[2][1<<MAXN];
int oneNumber[1<<MAXN];

inline int getOneNumber(int x)
{
    int cnt = 0;
    for(int i=0;(1<<i)<=x;++i)
    {
        if(x & (1 << i))
        {
            ++ cnt;
        }
    }
    return cnt;
}

void init()
{
    for(int i=0;i<(1<<MAXN);++i)
    {
        oneNumber[i] = getOneNumber(i);
    }
}

int main()
{
    init();
    while(~scanf("%d%d%d", &n, &m, &mn))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%d", &hit[i][j]);
            }
        }
        scanf("%d", &l);
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        for(int i=1;i<=l;++i)
        {
            int now = i & 1;
            int pre = 1 - now;
            scanf("%d", &monster);
            memcpy(dp[now], dp[pre], sizeof(dp[now]));
            for(int j=0;j<(1<<n);++j)
            {
                if(dp[pre][j] != -1)
                {
                    for(int k=0;k<n;++k)
                    {
                        if(j & (1 << k))
                        {
                            int state = j ^ (1 << k);
                            dp[now][state] = max(dp[now][state], dp[pre][j] + hit[k][monster]);
                            ans = max(ans, dp[now][state]);
                        }
                        else
                        {
                            if(oneNumber[j] < mn)
                            {
                                int state = j | (1 << k);
                                dp[now][state] = max(dp[now][state], dp[pre][j]);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
