#include <cstdio>
#include <cstring>
const int MAXN = 505;

bool g[MAXN][MAXN];
int m, n;

int link[MAXN];
bool visit[MAXN];

bool find(int x)
{
    for(int i=1;i<=n;++i)
    {
        if(g[x][i] && !visit[i])
        {
            visit[i] = true;
            if(link[i] == 0 || find(link[i]))
            {
                link[i] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int cnt = 0;
    memset(link, 0, sizeof(link));
    for(int i=1;i<=n;++i)
    {
        memset(visit, false, sizeof(visit));
        cnt += find(i);
    }
    return cnt;
}

int main()
{
    int u, v;
    while(scanf("%d%d",&n,&m), n || m)
    {
        memset(g, false, sizeof(g));
        while(m--)
        {
            scanf("%d%d",&u,&v);
            g[u][v] = true;
        }
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    g[i][j] |= g[i][k] && g[k][j];
        printf("%d\n", n - hungary());
    }
    return 0;
}
