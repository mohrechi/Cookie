#include<stdio.h>
#include<string.h>
#define Min(a,b) (a)<(b)?(a):(b)
#define Max(a,b) (a)>(b)?(a):(b)
#define INF 0xFFFFFFF
int dp[15][10005];
int vol[15][105];
int val[15][105];
int num[15];
int main()
{
    int n,m,t;
    int a,b,c;
    int i,j,k,mark;
    int count;
    int ans;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        memset(num,0,sizeof(num));
        for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            vol[a][num[a]]=b;
            val[a][num[a]]=c;
            num[a]++;
        }
        for(i=0;i<=t;i++)
            for(j=0;j<=m;j++)
                dp[i][j]=-INF;
        dp[0][0]=0;
        count=0;
        for(i=1;i<=t;i++)
        {
            if(num[i])
                count++;
            for(j=0;j<num[i];j++)
                for(k=m;k>=vol[i][j];k--)
                {
                    if(dp[i][k-vol[i][j]]!=-INF&& dp[i][k-vol[i][j]]+val[i][j]>dp[i][k])
                        dp[i][k]=dp[i][k-vol[i][j]]+val[i][j];
                    if(dp[i-1][k-vol[i][j]]!=-INF&& dp[i-1][k-vol[i][j]]+val[i][j]>dp[i][k])
                        dp[i][k]=dp[i-1][k-vol[i][j]]+val[i][j];
                }
        }
        ans=-1;
        for(i=m;i>=0;i--)
            if(ans<dp[t][i])
                ans=dp[t][i];
        if(count<t|| ans==-1)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
