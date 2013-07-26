#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
const int MAXM = 1000000 * 2 + 10;

int n, m;
struct Edge
{
    int v, w, next;
} edge[MAXM];
int head[MAXN], edgeNum;
int bridgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = 0;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v)
{
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

int dfn[MAXN], low[MAXN], timeStamp;

void dfs(int u, int f)
{
    dfn[u] = low[u] = timeStamp++;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        if (i == f)
        {
            continue;
        }
        int v = edge[i].v;
        if (dfn[v] == -1)
        {
            dfs(v, i ^ 1);
            if (dfn[u] < low[v])
            {
                edge[i].w = 1;
                edge[i ^ 1].w = 1;
                ++bridgeNum;
            }
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void tarjan()
{
    timeStamp = 0;
    bridgeNum = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    for (int i = 0; i < n; ++i)
    {
        if (dfn[i] == -1)
        {
            dfs(i, -1);
        }
    }
}

int queue[MAXN];
int dist[MAXN];
bool visit[MAXN];

int bfs(int s)
{
    int front = 0, rear = 1;
    memset(dist, -1, sizeof(dist));
    memset(visit, false, sizeof(visit));
    queue[0] = s;
    dist[s] = 0;
    visit[s] = true;
    int index = 1;
    int maxDist = 0;
    while (front < rear)
    {
        int u = queue[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (!visit[v])
            {
                dist[v] = dist[u] + w;
                visit[v] = true;
                queue[rear++] = v;
                if (dist[v] > maxDist)
                {
                    maxDist = dist[v];
                    index = v;
                }
            }
        }
    }
    return index;
}

int main()
{
    int u, v;
    while (~scanf("%d%d", &n, &m), n || m)
    {
        clearEdge();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            if (u == v)
            {
                continue;
            }
            addEdge(u, v);
        }
        tarjan();
        int s = bfs(1);
        int t = bfs(s);
        printf("%d\n", bridgeNum - dist[t]);
    }
}
