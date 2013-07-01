#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20005;
const int MAXM = 200005;

int n, m, k, q;
struct Edge
{
    int v, w, next;
} edge[MAXM * 2];
int head[MAXN], edgeNum;
bool visit[MAXN];
int dist[MAXN];
int queue[MAXN];

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

int main()
{
    int T, u, v, w;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        clearEdge();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        memset(visit, false, sizeof(visit));
        memset(dist, -1, sizeof(dist));
        int front = 0, rear = 0;
        scanf("%d", &k);
        for (int i = 0; i < k; ++i)
        {
            scanf("%d", &u);
            visit[u] = true;
            dist[u] = 0;
            queue[rear++] = u;
        }
        while (front != rear)
        {
            int u = queue[front];
            for (int i = head[u]; i != -1; i = edge[i].next)
            {
                int v = edge[i].v;
                int w = edge[i].w;
                if (dist[v] == -1 || dist[v] > dist[u] + w)
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
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d", &u);
            printf("%d\n", dist[u]);
        }
        printf("\n");
    }
    return 0;
}
