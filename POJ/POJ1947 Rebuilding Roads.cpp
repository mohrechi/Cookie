#include<stdio.h>
#define MAXN 155
#define INF 1000000000
int n,p,graph[MAXN][MAXN],dp[MAXN][MAXN];

inline int min(int x, int y)
{
    return x<y?x:y;
}

void calcTree(int x)
{
    for(int i=0;i<=p;i++)
	{
		dp[x][i]=INF;
	}
	dp[x][1]=0;
	for(int i=0;i<graph[x][0];i++)
	{
		calcTree(graph[x][i+1]);
		for(int j=p;j>0;j--)
		{
			dp[x][j]=dp[x][j]+1;
			for(int k=1;k<j;k++)
			{
				dp[x][j]=min(dp[x][j],dp[x][k]+dp[graph[x][i+1]][j-k]);
			}
		}
	}
}

int main()
{
    int x,y,root=1;
    scanf("%d%d",&n,&p);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        graph[x][++graph[x][0]]=y;
    }
    calcTree(1);
    int answer=dp[1][p];
    for(int i=2;i<n;i++)
    {
        answer=min(answer, dp[i][p]+1);
    }
    printf("%d\n",answer);
    return 0;
}
