#include <cstdio>
#include <cstring>
static const int MAXN = 10005;
static const int MAXM = 50005;
struct Edge
{
    int v, next, visited;
}edge[MAXM*2];
int head[MAXN], n, m;
int edgeNumber;

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    edge[edgeNumber].visited = false;
    head[u] = edgeNumber++;
}

void search(int cur)
{
    for(int i = head[cur];i!=-1;i = edge[i].next)
    {
        if(!edge[i].visited)
        {
            edge[i].visited = true;
            search(edge[i].v);
        }
    }
    printf("%d\n",cur);
}

int main(int argc, char *argv[])
{
    int x, y;
    scanf("%d%d",&n,&m);
    memset(head, -1, sizeof(head));
    edgeNumber = 0;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&x,&y);
        addEdge(x, y);
        addEdge(y, x);
    }
    search(1);
    return 0;
}
