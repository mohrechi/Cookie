#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;
const int MAXM = 20005;

int n, m, money;
struct Edge
{
    int v, w, next;
} edge[MAXM];
int head[MAXN], edgeNumber;

inline void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

bool visit[MAXN];
int queue[MAXN];
int dist[MAXN];

void spfa()
{
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    visit[0] = true;
    dist[0] = money;
    queue[0] = 0;
    int front = 0, rear = 1;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(dist[v] == -1 || dist[v] > dist[u] + w || dist[v] > (dist[u] << 1))
            {
                dist[v] = min(dist[u] + w, dist[u] << 1);
                if(!visit[v])
                {
                    visit[v] = true;
                    queue[rear] = v;
                    if(++ rear >= MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if(++ front >= MAXN)
        {
            front = 0;
        }
    }
}

int main()
{
    int u, v, w;
    while(scanf("%d", &n), n + 1)
    {
        scanf("%d%d", &m, &money);
        initEdge();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        spfa();
        printf("%d\n", dist[n - 1]);
    }
    return 0;
}
