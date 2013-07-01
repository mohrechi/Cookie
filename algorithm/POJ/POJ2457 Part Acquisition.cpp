#include <cstdio>
#include <cstring>
static const int MAXN = 1010;
static const int MAXM = 50010;

struct Edge
{
    int v, next;
}edge[MAXM];
int edgeNumber, head[MAXN];
int n, m;

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

bool visited[MAXN];
int pre[MAXN];
int queue[MAXN];

void bfs()
{
    int front = 0, rear = 1;
    memset(visited, false, sizeof(visited));
    memset(pre, -1, sizeof(pre));
    queue[0] = 1;
    visited[1] = true;
    pre[1] = 0;
    while(front < rear)
    {
        int u = queue[front++];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(!visited[v])
            {
                visited[v] = true;
                pre[v] = u;
                queue[rear++] = v;
            }
        }
    }
}

int ans[MAXN], ansNumber;

int main()
{
    int u, v;
    scanf("%d%d",&m,&n);
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&u,&v);
        addEdge(u, v);
    }
    bfs();
    if(pre[n] == -1)
    {
        printf("-1\n");
    }
    else
    {
        ansNumber = 0;
        while(pre[n])
        {
            ans[ansNumber++] = n;
            n = pre[n];
        }
        printf("%d\n1\n", ansNumber+1);
        while(ansNumber--)
        {
            printf("%d\n", ans[ansNumber]);
        }
    }
    return 0;
}
