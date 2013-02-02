#include <cstdio>
#include <cstring>
static const int MAXN = 500010;
static const int MAXM = 500010;
static const int INF = 0x7FFFFFFF;

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int use[MAXN], unuse[MAXN];

struct Edge
{
    int v, next, w;
}edge[MAXM];
int edgeNumber;
int head[MAXN];
int n, m;
int que[MAXM];
bool visited[MAXN];

void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

int main(int argc, char *argv[])
{
    int u, v, w;
    while(~scanf("%d%d",&n,&m))
    {
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        for(int i=1;i<=n;++i)
        {
            use[i] = INF;
            unuse[i] = INF;
        }
        int front = 0, rear = 1;
        que[0] = 1;
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        use[1] = 0;
        unuse[1] = 0;
        while(front != rear)
        {
            u = que[front];
            for(int i=head[u];i!=-1;i=edge[i].next)
            {
                v = edge[i].v;
                w = edge[i].w;
                bool flag = false;
                if(unuse[v] > unuse[u] + w)
                {
                    unuse[v] = unuse[u] + w;
                    flag = true;
                }
                if(use[v] > unuse[u])
                {
                    use[v] = unuse[u];
                    flag = true;
                }
                if(use[v] > use[u] + w)
                {
                    use[v] = use[u] + w;
                    flag = true;
                }
                if(flag && !visited[v])
                {
                    visited[v] = true;
                    que[rear] = v;
                    if(++rear >= MAXM)
                    {
                        rear = 0;
                    }
                }
            }
            visited[u] = false;
            if(++front >= MAXM)
            {
                front = 0;
            }
        }
        if(use[n] == INF)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", use[n]);
        }
    }
    return 0;
}
