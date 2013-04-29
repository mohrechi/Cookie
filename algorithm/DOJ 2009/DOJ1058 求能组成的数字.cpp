#include <cstdio>
#include <cstring>
static const int MAXN = 201;
static const int MAXM = 101;

bool dp[MAXN * MAXM], flag;
int n, sum, ans, a[MAXN];

int main()
{
    scanf("%d", &n);
    flag = false;
    for(int i=0;i<n;++i)
    {
        scanf("%d", &a[i]);
        if(!a[i])
        {
            flag = true;
        }
    }
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    dp[a[0]] = true;
    sum = a[0];
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<=sum;++j)
        {
            if(dp[j])
            {
                dp[j + a[i]] = true;
            }
        }
        sum += a[i];
    }
    ans = flag?0:-1;
    for(int i=0;i<=sum;++i)
    {
        if(dp[i])
        {
            ++ ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}
