#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5001;

struct Edge
{
    int u, v, w;
} edge[MAXN * MAXN];

int n, m;
int graph[MAXN][MAXN];
int sum[MAXN];
bool deleted[MAXN];
bool visit[MAXN][MAXN];

int main()
{
    int q, a, b;
    while(~scanf("%d%d", &n, &m))
    {
        memset(graph, 0, sizeof(graph));
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
            graph[edge[i].u][edge[i].v] += edge[i].w;
        }
        memset(sum, 0, sizeof(sum));
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                sum[i] += graph[i][j];
            }
        }
        memset(deleted, false, sizeof(deleted));
        memset(visit, false, sizeof(visit));
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &a, &b);
            switch(a)
            {
                case 1:
                    deleted[b] = true;
                    for(int i=1;i<=n;++i)
                    {
                        if(!visit[b][i])
                        {
                            visit[b][i] = true;
                            sum[b] -= graph[b][i];
                        }
                        if(!visit[i][b])
                        {
                            visit[i][b] = true;
                            sum[i] -= graph[i][b];
                        }
                    }
                    break;
                case 2:
                    deleted[b] = false;
                    for(int i=1;i<=n;++i)
                    {
                        if(!deleted[i])
                        {
                            if(visit[b][i])
                            {
                                visit[b][i] = false;
                                sum[b] += graph[b][i];
                            }
                            if(visit[i][b])
                            {
                                visit[i][b] = false;
                                sum[i] += graph[i][b];
                            }
                        }
                    }
                    break;
                case 3:
                    ++ graph[edge[b].u][edge[b].v];
                    if(!visit[edge[b].u][edge[b].v])
                    {
                        ++ sum[edge[b].u];
                    }
                    break;
            }
            int ans = 0;
            for(int i=1;i<=n;++i)
            {
                ans += sum[i];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
