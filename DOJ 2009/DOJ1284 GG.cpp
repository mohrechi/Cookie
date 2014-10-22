#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 201;

int n, m;
int conn[MAXN][MAXN], graph[MAXN][MAXN], num[MAXN][MAXN];
int u[MAXN], v[MAXN], ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d", &graph[i][j]);
                conn[i][j] = graph[i][j];
            }
        }
        memset(num, 0, sizeof(num));
        scanf("%d", &m);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d", &u[i], &v[i]);
            graph[u[i]][v[i]] = -1;
            ++ num[u[i]][v[i]];
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(graph[i][k] == -1)
                    {
                        continue;
                    }
                    if(graph[k][j] == -1)
                    {
                        continue;
                    }
                    int d = graph[i][k] + graph[k][j];
                    if(graph[i][j] == -1)
                    {
                        graph[i][j] = d;
                    }
                    else
                    {
                        graph[i][j] = min(graph[i][j], d);
                    }
                }
            }
        }
        for(int k=m-1;k>=0;--k)
        {
            ans[k] = 0;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(ans[k] == -1)
                    {
                        continue;
                    }
                    if(graph[i][j] == -1)
                    {
                        ans[k] = -1;
                        continue;
                    }
                    ans[k] += graph[i][j];
                }
            }
            if(k)
            {
                int uu = u[k];
                int vv = v[k];
                -- num[uu][vv];
                if(num[uu][vv])
                {
                    continue;
                }
                if(graph[uu][vv] != -1 && graph[uu][vv] < conn[uu][vv])
                {
                    continue;
                }
                graph[uu][vv] = conn[uu][vv];
                for(int i=1;i<=n;++i)
                {
                    for(int j=1;j<=n;++j)
                    {
                        if(graph[i][uu] == -1)
                        {
                            continue;
                        }
                        if(graph[vv][j] == -1)
                        {
                            continue;
                        }
                        int d = graph[i][uu] + graph[uu][vv] + graph[vv][j];
                        if(graph[i][j] == -1)
                        {
                            graph[i][j] = d;
                        }
                        else
                        {
                            graph[i][j] = min(graph[i][j], d);
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;++i)
        {
            if(ans[i] == -1)
            {
                printf("INF\n");
            }
            else
            {
                printf("%d\n", ans[i]);
            }
        }
    }
    return 0;
}
