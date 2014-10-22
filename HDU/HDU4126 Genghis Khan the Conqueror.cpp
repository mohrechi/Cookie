#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 3005;
const int INF = 0x3f3f3f3f;

int n, m;
int graph[MAXN][MAXN];
int index[MAXN], dist[MAXN], father[MAXN];
bool visit[MAXN];

int prim()
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        father[i] = -1;
        dist[i] = graph[0][i];
        index[i] = 0;
        visit[i] = false;
    }
    visit[0] = true;
    for (int k = 1; k < n; ++k)
    {
        int minValue = INF;
        int minIndex = -1;
        for (int i = 1; i < n; ++i)
        {
            if (!visit[i])
            {
                if (dist[i] < minValue)
                {
                    minValue = dist[i];
                    minIndex = i;
                }
            }
        }
        sum += dist[minIndex];
        father[minIndex] = index[minIndex];
        visit[minIndex] = true;
        for (int i = 1; i < n; ++i)
        {
            if (!visit[i])
            {
                if (graph[minIndex][i] < dist[i])
                {
                    dist[i] = graph[minIndex][i];
                    index[i] = minIndex;
                }
            }
        }
    }
    return sum;
}

struct Edge
{
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;
bool isAncestor[MAXN][MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void build()
{
    clearEdge();
    for (int i = 1; i < n; ++i)
    {
        addEdge(father[i], i);
    }
    memset(isAncestor, false, sizeof(isAncestor));
    for (int i = 1; i < n; ++i)
    {
        int f = father[i];
        while (f != -1)
        {
            isAncestor[f][i] = true;
            f = father[f];
        }
    }
}

int dp[MAXN][MAXN];
int sub[MAXN][MAXN];

void dfs(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        dfs(edge[i].v);
    }
    int ans = INF;
    for (int i = 0; i < n; ++i)
    {
        if (!isAncestor[u][i] && u != i)
        {
            for (int j = head[u]; j != -1; j = edge[j].next)
            {
                int v = edge[j].v;
                dp[u][i] = min(dp[u][i], dp[v][i]);
            }
            if (father[u] != i)
            {
                dp[u][i] = min(dp[u][i], graph[u][i]);
            }
            ans = min(ans, dp[u][i]);
        }
    }
    if (father[u] != -1)
    {
        sub[father[u]][u] = ans;
        sub[u][father[u]] = ans;
    }
}

int main()
{
    int u, v, w;
    while (scanf("%d%d", &n, &m), n || m)
    {
        memset(graph, 0x3f, sizeof(graph));
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            graph[u][v] = graph[v][u] = w;
        }
        int mst = prim();
        build();
        memset(dp, 0x3f, sizeof(dp));
        memset(sub, -1, sizeof(sub));
        dfs(0);
        scanf("%d", &m);
        int q = m;
        double ans = 0.0;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            if (sub[u][v] == -1)
            {
                ans += mst;
            }
            else
            {
                ans += mst + min(w, sub[u][v]) - graph[u][v];
            }
        }
        printf("%.4lf\n", ans / q);
    }
    return 0;
}
