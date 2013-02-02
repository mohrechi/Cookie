#include <cstdio>
#include <cstring>

static const int MAXN = 105;
int n, m;
int g[MAXN][MAXN];

int main()
{
    int u, v, w;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d", &g[i][j]);
            }
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(g[i][j] > g[i][k] + g[k][j])
                    {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(g[u][v] > w)
            {
                g[u][v] = w;
                for(int i=1;i<=n;++i)
                {
                    for(int j=1;j<=n;++j)
                    {
                        if(g[i][j] > g[i][u] + g[v][j] + w)
                        {
                            g[i][j] = g[i][u] + g[v][j] + w;
                        }
                        if(g[i][j] > g[i][v] + g[u][j] + w)
                        {
                            g[i][j] = g[i][v] + g[u][j] + w;
                        }
                    }
                }
            }
            int sum = 0;
            for(int i=1;i<=n;++i)
            {
                for(int j=i+1;j<=n;++j)
                {
                    sum += g[i][j];
                }
            }
            printf("%d\n", sum);
        }
    }
    return 0;
}
