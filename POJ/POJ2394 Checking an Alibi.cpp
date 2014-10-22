#include <cstdio>
#include <cstring>
static const int MAXF = 505;
static const int MAXP = 1005;
static const int MAXC = 105;

int f, p, c, m;
struct Edge
{
    int v, w, next;
}edge[MAXP * 2];
int edgeNumber, head[MAXF];
int position[MAXC];
int ans[MAXC], ansNumber;

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int queue[MAXF], dist[MAXF];
bool visited[MAXF];

int find(int position)
{
    for(int i=1;i<=f;++i)
    {
        dist[i] = 1000000000;
    }
    memset(visited, false, sizeof(visited));
    queue[0] = 1;
    visited[1] = true;
    dist[1] = 0;
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
                    if(++rear >= MAXF)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visited[u] = false;
        if(++front >= MAXF)
        {
            front = 0;
        }
    }
    return dist[position];
}

int main()
{
    int u, v, w;
    while(~scanf("%d%d%d%d",&f,&p,&c,&m))
    {
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=0;i<p;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        for(int i=0;i<c;++i)
        {
            scanf("%d", &position[i]);
        }
        ansNumber = 0;
        for(int i=0;i<c;++i)
        {
            if(find(position[i])<=m)
            {
                ans[ansNumber++] = i+1;
            }
        }
        printf("%d\n", ansNumber);
        for(int i=0;i<ansNumber;++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
