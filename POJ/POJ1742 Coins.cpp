#include <cstdio>
#include <cstring>
static const int MAXN = 105;
static const int MAXM = 100005;
int n,m,a[MAXN],c[MAXN],u[MAXM];
bool dp[MAXM];
int main(int argc, char *argv[])
{
    while(scanf("%d%d",&n,&m), n || m)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d",&c[i]);
        }
        memset(dp, false, sizeof(dp));
        int ans = 0;
        dp[0] = true;
        for(int i=0;i<n;++i)
        {
            memset(u, 0, sizeof(u));
            for(int j=a[i];j<=m;++j)
            {
                if(dp[j-a[i]] && !dp[j] && u[j-a[i]] < c[i])
                {
                    dp[j] = true;
                    u[j] = u[j-a[i]] + 1;
                    ++ ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
