#include<stdio.h>
#include<memory.h>

int max(int x, int y)
{
    return x>y?x:y;
}

int main()
{
    int n,m,w[3500],d[3500],dp[13000];
    scanf("%d%d",&n,&m);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&w[i],&d[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=m;j>=w[i];j--)
        {
            dp[j]=max(dp[j-w[i]]+d[i],dp[j]);
        }
    }
    int maxD=-1;
    for(int i=1;i<=m;i++)
    {
        if(dp[i]>maxD)
        {
            maxD=dp[i];
        }
    }
    printf("%d\n",maxD);
    return 0;
}
