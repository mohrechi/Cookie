#include<stdio.h>
#include<stdlib.h>
int F,V,A[105][105],dp[105][105];
inline int max(int x, int y)
{
    return x>y?x:y;
}
int main()
{
    scanf("%d%d",&F,&V);
    for(int i=1;i<=F;i++)
    {
        for(int j=1;j<=V;j++)
        {
            scanf("%d",&A[i][j]);
            dp[i][j]=-999999999;
        }
    }
    dp[1][1]=A[1][1];
    for(int i=2;i<=V;i++)
    {
        dp[1][i]=max(dp[1][i-1], A[1][i]);
    }
    for(int i=2;i<=F;i++)
    {
        for(int j=1;j<=V;j++)
        {
            if(i!=j) dp[i][j]=max(dp[i-1][j-1]+A[i][j], dp[i][j-1]);
            else dp[i][j]=dp[i-1][j-1]+A[i][j];
        }
    }
    printf("%d\n",dp[F][V]);
    return 0;
}
