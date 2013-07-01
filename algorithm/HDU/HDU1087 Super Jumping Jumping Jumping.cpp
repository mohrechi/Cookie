#include<stdio.h>
#include<string.h>
#define LL long long
#define N 1005
int main()
{
    int n,i,j;
    LL a[N],dp[N],max;
    while (scanf("%d",&n)&&n)
    {
        for (i=1;i<=n;++i) scanf("%I64d",&a[i]);
        max=0;
        for (i=1;i<=n;++i)
        {
            dp[i]=a[i];
            if (dp[i]>max) max=dp[i];
            for (j=1;j<i;++j)
            {
                if (a[j]<a[i] && dp[j]+a[i]>dp[i])
                {
                    dp[i]=dp[j]+a[i];
                    if (dp[i]>max) max=dp[i];
                }
            }
        }
        printf("%I64d\n",max);
    }
    return 0;
}
