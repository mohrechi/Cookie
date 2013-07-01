#include <cstdio>
#include <cstring>
static const int MAXN = 50005;
static const int MAXM = 50005;
static const int MAXP = 50005;

struct Edge
{
    int v, w, next;
}edge[MAXM * 2];
int edgeNumber;
int head[MAXN];
int source[MAXN];
int destination[MAXN];
int n,m,q;

void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

bool visited[MAXN];
int queue[MAXN];

void bfs(int dist[], int start)
{
    for(int i=1;i<=n;++i)
    {
        dist[i] = 1000000000;
    }
    dist[start] = 0;
    memset(visited, false, sizeof(visited));
    visited[start] = true;
    queue[0] = start;
    int front = 0, rear = 1;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                if(!visited[v])
                {
                    visited[v] = true;
                    queue[rear] = v;
                    if(++rear == MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visited[u] = false;
        if(++front == MAXN)
        {
            front = 0;
        }
    }
}

int main()
{
    int u, v, w;
    while(~scanf("%d%d%d",&n,&m,&q))
    {
        memset(head, -1, sizeof(head));
        edgeNumber = 0;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        bfs(source, 1);
        bfs(destination, n);
        for(int i=0;i<q;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            if(source[u] + destination[v] + w < source[n])
            {
                printf("%d\n", source[u] + destination[v] + w);
            }
            else if(source[v] + destination[u] + w < source[n])
            {
                printf("%d\n", source[v] + destination[u] + w);
            }
        }
    }
    return 0;
}
