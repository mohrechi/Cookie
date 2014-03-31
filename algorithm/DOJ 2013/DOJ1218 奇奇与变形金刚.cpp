#include <cstdio>
#include <cstring>
const int MAXN = 10000 + 10;
const int MAXM = 50000 + 10;

int n, m;
struct Edge
{
    int v, w, next;
} edge[MAXM];
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

bool visit[MAXN];
int queue[MAXN];
long long dist[MAXN];

long long spfa(int s, int t)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, 0x3f, sizeof(dist));
    visit[s] = true;
    dist[s] = 0;
    queue[0] = s;
    while (front != rear)
    {
        int u = queue[front];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                if (!visit[v])
                {
                    visit[v] = true;
                    queue[rear] = v;
                    if (++rear >= MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if (++front >= MAXN)
        {
            front = 0;
        }
    }
    return dist[t];
}

int main()
{
    int T;
    int u, v, w;
    scanf("%d", &T);
    while (T--)
    {
        clearEdge();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        scanf("%d%d%d", &u, &v, &w);
        printf("%lld\n", spfa(u, v) + spfa(v, w));
    }
    return 0;
}
