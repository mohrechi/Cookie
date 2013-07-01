#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
const int N=1000001;
long long dp[N],a[N];

int main()
{
    long long n;
    while(scanf("%lld",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        long long sum=0;
        for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
        dp[1]=1;
        for(long long i=2;i<=n;i++)
        {
            for(long long j=i-1;j>=1;j--)
            {
                if(a[j]>=a[i]) {dp[i]=dp[j]+1;break;}
                else dp[i]=1;
            }
        }
        for(long long i=2;i<=n;i++)
        {
            if(a[i]>=a[i-1])
            {
                for(int j=i-1;j>=1;j--)
                {
                    if(a[j]>a[i]) {sum+=dp[i-1]-dp[j]+1;break;}
                    if(j==1 && a[j]<=a[i]) sum+=dp[i-1];
                }
            }
            else sum+=1;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
