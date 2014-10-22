#include <cstdio>
#include <cstring>
const int MAXN = 50005;
const int MAXM = MAXN * 51;

struct Edge
{
    int v, w, next;
}edge[MAXM];
int edgeNumber, head[MAXN];

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int n;
int queue[MAXN];
bool visit[MAXN];
double dist[MAXN];
bool flag;

void bfs(int s, int t)
{
    for(int i=1;i<=n;++i)
    {
        dist[i] = 0.0;
        visit[i] = false;
    }
    queue[0] = s;
    visit[s] = true;
    dist[s] = 1.0;
    int front = 0, rear = 1;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(dist[v] < dist[u] * (100 - w) / 100.0)
            {
                dist[v] = dist[u] * (100 - w) / 100.0;
                if(!visit[v])
                {
                    visit[v] = true;
                    queue[rear] = v;
                    if(v == t)
                    {
                        flag = true;
                    }
                    if(++rear >= MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if(++front >= MAXN)
        {
            front = 0;
        }
    }
}

int main()
{
    int k, v, w, s, t, m;
    while(~scanf("%d", &n))
    {
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &k);
            while(k--)
            {
                scanf("%d%d", &v, &w);
                addEdge(i, v, w);
            }
        }
        scanf("%d%d%d", &s, &t, &m);
        flag = false;
        bfs(s, t);
        if(flag)
        {
            printf("%.2lf\n", m * (1.0 - dist[t]));
        }
        else
        {
            printf("IMPOSSIBLE!\n");
        }
    }
    return 0;
}
