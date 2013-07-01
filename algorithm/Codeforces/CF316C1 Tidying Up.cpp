#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
const int DIR_X[] = {1, 0, -1, 0};
const int DIR_Y[] = {0, 1, 0, -1};

int n, m;
int a[MAXN][MAXN];
int src, dst;

struct Edge
{
    int u, v, w, c;
    int next;
} edge[MAXN * MAXN * MAXN];
int head[MAXN * MAXN], edgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w, int c)
{
    edge[edgeNum].u = u;
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].c = c;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w, int c)
{
    addEdgeSub(u, v, w, c);
    addEdgeSub(v, u, -w, 0);
}

int queue[MAXN * MAXN];
bool visit[MAXN * MAXN];
int dist[MAXN * MAXN];
int prev[MAXN * MAXN];

bool bfs()
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, 0x3f, sizeof(dist));
    memset(prev, -1, sizeof(prev));
    queue[0] = src;
    visit[src] = true;
    dist[src] = 0;
    while (front != rear)
    {
        int u = queue[front];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            int c = edge[i].c;
            if (c && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                prev[v] = i;
                if (!visit[v])
                {
                    visit[v] = true;
                    queue[rear] = v;
                    if (++rear >= MAXN * MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if (++front >= MAXN * MAXN)
        {
            u = 0;
        }
    }
    return dist[dst] != INF;
}

int maxflow()
{
    int cost = 0;
    while (bfs())
    {
        int temp = dst;
        int flow = INF;
        while (prev[temp] != -1)
        {
            flow = min(flow, edge[prev[temp]].c);
            temp = edge[prev[temp]].u;
        }
        temp = dst;
        while (prev[temp] != -1)
        {
            edge[prev[temp]].c -= flow;
            edge[prev[temp] ^ 1].c += flow;
            temp = edge[prev[temp]].u;
        }
        cost += dist[dst];
    }
    return cost;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        clearEdge();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        src = 0;
        dst = m * n + 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if ((i + j) & 1)
                {
                    addEdge(src, i * m + j + 1, 0, 1);
                    for (int k = 0; k < 4; ++k)
                    {
                        int ti = i + DIR_X[k];
                        int tj = j + DIR_Y[k];
                        if (ti >= 0 && ti < n)
                        {
                            if (tj >= 0 && tj < m)
                            {
                                if (a[i][j] == a[ti][tj])
                                {
                                    addEdge(i * m + j + 1, ti * m + tj + 1, 0, 1);
                                }
                                else
                                {
                                    addEdge(i * m + j + 1, ti * m + tj + 1, 1, 1);
                                }
                            }
                        }
                    }
                }
                else
                {
                    addEdge(i * m + j + 1, dst, 0, 1);
                }
            }
        }
        printf("%d\n", maxflow());
    }
    return 0;
}
