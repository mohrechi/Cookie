#include<stdio.h>

long long slove(long long n,long long k)
{
    long long d,low,high,next,ans=0;
    if(n>k)
    {
        ans=ans+(n-k)*k;
        n=k;
    }
    d=k/n;
    while(n>1)
    {
        next=k/(d+1);
        if(next==n)
        {
                ans=ans+k%n;
                n--;
                d=k/n;
                continue;
        }
        low=k%n;
        high=k%(next+1);
        ans=ans+(((low+high)*(n-next))>>1);
        n=next;
        d++;
    }
    return ans;
}

int main()
{
    long long n,k;
    while(scanf("%lld%lld",&n,&k)!=EOF)
    {
        printf("%lld\n",slove(n,k));
    }
    return 0;
}
