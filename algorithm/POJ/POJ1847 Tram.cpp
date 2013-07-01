#include <cstdio>
static const int MAXN = 105;
int dist[MAXN][MAXN];
int n, a, b;

int main(int argc, char *argv[])
{
    while(~scanf("%d%d%d", &n, &a, &b))
    {
        int i, j, k, t;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                dist[i][j] = 1000000000;
        for(i=1;i<=n;++i)
        {
            scanf("%d",&k);
            for(j=0;j<k;++j)
            {
                scanf("%d",&t);
                dist[i][t] = j?1:0;
            }
        }
        for(k=1;k<=n;++k)
            for(i=1;i<=n;++i)
                for(j=1;j<=n;++j)
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
        printf("%d\n",dist[a][b]>1000?-1:dist[a][b]);
    }
    return 0;
}
