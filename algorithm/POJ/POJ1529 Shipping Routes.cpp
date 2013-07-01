#include<stdio.h>
#include<string.h>
const int INF = 9999999;
int m,n,p,t,sets;
char point[31][5];
int mat[31][31];
char from[5],to[5];
int i,j,k,r;
int start,end,times;
int find(char *from)
{
    int i;
    for( i = 1; i <= m; i++ )
    {
        if(strcmp(from,point[i])==0)
            return i;
    }
}
int main()
{
    scanf("%d",&sets);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for( i = 1; i <= sets; i++)
    {
        printf("DATA SET %d\n\n",i);
        scanf("%d%d%d",&m,&n,&p);
        for( j = 1; j <= m; j++ )
            for( k = 1; k <= m; k++ )
                mat[j][k] = INF;
        for( j = 1; j <= m; j++ )
        {
            scanf("%s",point[j]);
            mat[j][j] = 0;
        }
        for( j = 1; j <= n; j++ )
        {
            scanf("%s%s",from,to);
            start = find(from);
            end = find(to);
            mat[start][end] = mat[end][start] = 1;
        }
        for( k = 1; k <= m; k++ )
            for( j = 1; j <= m; j++ )
                for( r = 1; r <= m; r++ )
                    if(mat[j][r] > mat[j][k] + mat[k][r])
                        mat[j][r] = mat[j][k] + mat[k][r];
        for( j = 1; j <= p; j++ )
        {
            scanf("%d%s%s",&times,from,to);
            t = mat[find(from)][find(to)];
            if(t >= INF) printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n",100*t*times);
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
