#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;

int n;
struct Edge
{
    int v, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

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

bool visit[MAXN];
int queue[MAXN];
int dist[MAXN];
int maxDist;

int bfs(int src)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, 0x3f, sizeof(dist));
    visit[src] = true;
    dist[src] = 0;
    queue[front] = src;
    while (front < rear)
    {
        int u = queue[front];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
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
    int index = 0;
    maxDist = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] > maxDist)
        {
            maxDist = dist[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int T, u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        printf("%d\n", (dist[bfs(bfs(0))] + 1) >> 1);
    }
    return 0;
}
