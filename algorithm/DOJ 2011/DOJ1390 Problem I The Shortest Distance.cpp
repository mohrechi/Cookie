#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,n,m,graph[105][105];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                graph[i][j]=1000000000;
            }
        }
        while(m--)
        {
            int x, y, z;
            scanf("%d%d%d",&x,&y,&z);
            graph[x][y]=graph[y][x]=z;
        }
        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(graph[i][j]>graph[i][k]+graph[k][j])
                    {
                        graph[i][j]=graph[i][k]+graph[k][j];
                    }
                }
            }
        }
        if(graph[1][n]>500000000) printf("I CAN'T REACH END\n");
        else printf("%d\n",graph[1][n]);
    }
    return 0;
}
