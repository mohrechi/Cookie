#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int sum[400][400], dp[400][40],pos[400];
inline int min(int x, int y)
{
    return x<y?x:y;
}
int main()
{
    int v,p;
    while(scanf("%d%d",&v,&p)!=EOF)
    {
        for(int i=1;i<=v;i++)
        {
            scanf("%d",&pos[i]);
        }
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=v;i++)
        {
            for(int j=i+1;j<=v;j++)
            {
                sum[i][j]=sum[i][j-1]+pos[j]-pos[(i+j)>>1];
            }
        }
        for(int i=1;i<=v;i++)
        {
            dp[i][i]=0;
            dp[i][1]=sum[1][i];
        }
        for(int j=2;j<=p;j++)
        {
            for(int i=j+1;i<=v;i++)
            {
                dp[i][j]=999999999;
                for(int k=j-1;k<i;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[k][j-1]+sum[k+1][i]);
                }
            }
        }
        printf("%d\n",dp[v][p]);
    }
    return 0;
}
