#include <cstdio>
#include <cstring>
const int MAXN = 10010;

struct Edge
{
    int v, w, next;
}edge[MAXN * 2];
int edgeNumber, head[MAXN];
int destination, distance;

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int dist[MAXN];
int queue[MAXN];
int front, rear;
bool visit[MAXN];

void bfs(int start)
{
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    queue[0] = start;
    visit[start] = true;
    dist[start] = 0;
    front = 0, rear = 1;
    while(front < rear)
    {
        int u = queue[front++];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(dist[v] == -1 || dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                if(!visit[v])
                {
                    visit[v] = true;
                    queue[rear++] = v;
                }
            }
        }
    }
    destination = 1;
    distance = 0;
    for(int i=0;i<MAXN;++i)
    {
        if(dist[i] > distance)
        {
            distance = dist[i];
            destination = i;
        }
    }
}

int main()
{
    int u, v, w;
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    while(~scanf("%d%d%d",&u,&v,&w))
    {
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    bfs(1);
    bfs(destination);
    printf("%d\n", distance);
    return 0;
}
