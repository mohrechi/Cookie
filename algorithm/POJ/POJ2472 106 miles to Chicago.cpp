#include <cstdio>
#include <cstring>
static const int MAXN = 105;
double g[MAXN][MAXN];

int main()
{
    int n, m;
    int u, v, w;
    while(scanf("%d", &n), n)
    {
        scanf("%d", &m);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                g[i][j] = -1.0;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            g[u][v] = g[v][u] = w / 100.0;
        }
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    if(g[i][k] > 0)
                        if(g[k][j] > 0)
                            if(g[i][j] < g[i][k] * g[k][j])
                                g[i][j] = g[i][k] * g[k][j];
        printf("%.6lf percent\n", g[1][n] * 100.0);
    }
    return 0;
}
