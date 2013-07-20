#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const int MAXM = 1005;
const int MAXT = 305;
const int MAXS = 105;
const int INF = 0x3f3f3f3f;

int N, M, T, S, E;
struct Node
{
    int index;
    int cost;
    int satisfy;
    bool operator <(const Node &node) const
    {
        if (satisfy == node.satisfy)
        {
            return index < node.index;
        }
        return satisfy < node.satisfy;
    }
} node[MAXN];
int graph[MAXN][MAXN];

struct Edge
{
    int v, w, next;
} edge[MAXN * MAXN];
int head[MAXN], edgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int qu[MAXN * MAXT];
int qt[MAXN * MAXT];
int dist[MAXN][MAXT];
bool visit[MAXN][MAXT];

void spfa()
{
    int front = 0, rear = 1;
    memset(dist, -1, sizeof(dist));
    memset(visit, false, sizeof(visit));
    qu[0] = 0;
    qt[0] = 0;
    visit[0][0] = true;
    dist[0][0] = 0;
    while (front != rear)
    {
        int u = qu[front];
        int t = qt[front];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (t + w <= T && dist[v][t + w] < dist[u][t])
            {
                dist[v][t + w] = dist[u][t];
                if (!visit[v][t + w])
                {
                    visit[v][t + w] = true;
                    qu[rear] = v;
                    qt[rear] = t + w;
                    if (++rear >= MAXN * MAXT)
                    {
                        rear = 0;
                    }
                }
            }
            if (t + w + node[v].cost <= T && dist[v][t + w + node[v].cost] < dist[u][t] + node[v].satisfy)
            {
                dist[v][t + w + node[v].cost] = dist[u][t] + node[v].satisfy;
                if (!visit[v][t + w + node[v].cost])
                {
                    qu[rear] = v;
                    qt[rear] = t + w + node[v].cost;
                    if (++rear >= MAXN * MAXT)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u][t] = false;
        if (++front >= MAXN * MAXT)
        {
            front = 0;
        }
    }
}

int main()
{
    int W;
    int u, v, w;
    scanf("%d", &W);
    for (int cas = 1; cas <= W; ++cas)
    {
        scanf("%d%d%d%d%d", &N, &M, &T, &S, &E);
        ++S, ++E;
        node[0].index = 0;
        node[0].cost = 0;
        node[0].satisfy = 0;
        memset(graph, 0x3f, sizeof(graph));
        for (int i = 1; i <= N; ++i)
        {
            node[i].index = i;
            scanf("%d", &node[i].cost);
            graph[i][i] = 0;
        }
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &node[i].satisfy);
        }
        node[N + 1].index = N + 1;
        node[N + 1].cost = MAXT;
        node[N + 1].satisfy = MAXT;
        sort(node, node + N + 2);
        for (int i = 0; i < M; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            ++u;
            ++v;
            graph[u][v] = graph[v][u] = min(graph[u][v], w);
        }
        for (int k = 1; k <= N; ++k)
        {
            for (int i = 1; i <= N; ++i)
            {
                for (int j = 1; j <= N; ++j)
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        clearEdge();
        for (int i = 1; i <= N; ++i)
        {
            int u = node[i].index;
            addEdge(0, i, graph[S][u]);
            addEdge(i, N + 1, graph[u][E]);
            for (int j = i + 1; j <= N; ++j)
            {
                if (node[i].satisfy < node[j].satisfy)
                {
                    int v = node[j].index;
                    addEdge(i, j, graph[u][v]);
                }
            }
        }
        spfa();
        int ans = 0;
        for (int i = 0; i <= T; ++i)
        {
            ans = max(ans, dist[N + 1][i]);
        }
        printf("Case #%d:\n%d\n", cas, ans);
    }
    return 0;
}
