#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int n,m,d[205],p[205],caseNum=0,dp[25][1000],path[25][1000],result[25];
int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&p[i],&d[i]);
        }
        memset(dp,-1,sizeof(dp));
        memset(path,0,sizeof(path));
        int temp=20*m;
        dp[0][temp]=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<=2*temp;j++)
            {
                if(dp[i][j]>=0)
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(dp[i][j]+p[k]+d[k]>dp[i+1][j+p[k]-d[k]])
                        {
                            int x=i,y=j;
                            while(x>0 && path[x][y]!=k)
                            {
                                y-=p[path[x][y]]-d[path[x][y]];
                                x--;
                            }
                            if(x==0)
                            {
                                dp[i+1][j+p[k]-d[k]]=dp[i][j]+p[k]+d[k];
                                path[i+1][j+p[k]-d[k]]=k;
                            }
                        }
                    }
                }
            }
        }
        int i=temp, j,k=0;
        while(dp[m][i+k]<0&&dp[m][i-k]<0)
        {
            k++;
        }
        if(dp[m][i+k]>dp[m][i-k])
        {
            j=i+k;
        }
        else
        {
            j=i-k;
        }
        printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",++caseNum,(dp[m][j]+j-temp)/2,(dp[m][j]-j+temp)/2);
        for(int i=1;i<=m;i++)
        {
            result[i]=path[m-i+1][j];
            j-=p[result[i]]-d[result[i]];
        }
        qsort(result+1,m,sizeof(int),cmp);
        for(int i=1;i<=m;i++)
        {
            printf("%d ",result[i]);
        }
        printf("\n\n");
    }
    return 0;
}
