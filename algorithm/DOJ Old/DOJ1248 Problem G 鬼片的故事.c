#include<stdio.h>

int g[1001][1001];
main ()
{
    int m,n,i,j,judge;
    while((scanf("%d%d",&m,&n))!=EOF)
    {
        judge=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        for(i=1;i<m;i++)
        {
            for(j=1;j<n;j++)
            {
                if(g[i][j]+g[i+1][j+1]>g[i+1][j]+g[i][j+1])
                {
                    judge=1;
                    break;
                }
            }
            if (judge==1)break;
        }
        if (judge==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
