#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXK = 500 + 10;

int n, m, k;
int c[MAXK], type[MAXN];
int dist[MAXK][MAXK];
bool visit[MAXN];

struct Edge
{
    int v, next;
} edge[MAXN * 2];
int edgeNum, head[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(const int &u, const int &v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void dfs(int u)
{
    visit[u] = true;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (!visit[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int u, v, w;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d", &c[i]);
    }
    for (int i = 1, s = 0; i <= k; ++i)
    {
        for (int j = 0; j < c[i]; ++j)
        {
            type[++s] = i;
        }
    }
    clearEdge();
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= k; ++i)
    {
        dist[i][i] = 0;
    }
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &w);
        if (w == 0)
        {
            addEdge(u, v);
            addEdge(v, u);
        }
        u = type[u];
        v = type[v];
        if (dist[u][v] == -1 || dist[u][v] > w)
        {
            dist[u][v] = dist[v][u] = w;
        }
    }
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i)
    {
        if (type[i] != type[i - 1])
        {
            dfs(i);
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        if (!visit[i])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        puts("Yes");
        n = k;
        for (int k = 1; k <= n; ++k)
        {
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    if (dist[i][k] != -1)
                    {
                        if (dist[k][j] != -1)
                        {
                            if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j])
                            {
                                dist[i][j] = dist[i][k] + dist[k][j];
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                printf("%d ", dist[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        puts("No");
    }
    return 0;
}
