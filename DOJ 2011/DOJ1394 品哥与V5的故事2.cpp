#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
int max(int x, int y)
{
    return x>y?x:y;
}
int main()
{
    int n,x,y,dp[105][105];
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        while(n--)
        {
            scanf("%d%d",&x,&y);
            dp[x][y]++;
        }
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1])+dp[i][j];
            }
        }
        printf("%d\n",dp[100][100]);
    }
	return 0;
}
