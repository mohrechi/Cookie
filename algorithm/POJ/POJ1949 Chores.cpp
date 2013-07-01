#include <cstdio>
#include <cstring>
static const int MAXN = 10005;
int n, m, k, t, a, b, dp[MAXN];
int max(int x, int y)
{
    return x>y?x:y;
}
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    a = 0;
    for(int i=1;i<=n;++i)
    {
        m = 0;
        scanf("%d%d",&t,&k);
        while(k--)
        {
            scanf("%d",&b);
            m = max(m, dp[b]);
        }
        dp[i] = m + t;
        a = max(a, dp[i]);
    }
    printf("%d\n",a);
    return 0;
}
