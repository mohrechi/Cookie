#include <cstdio>
#include <cstring>
const int MAXN = 2024;
const int INF = 0x7FFFFFFF;
int n;
int b[MAXN][MAXN];
int c[MAXN], d[MAXN];
int depth[MAXN];

struct Edge
{
    int v, flow, next;
}edge[MAXN * MAXN * 2];
int edgeNumber, head[MAXN];

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline void addEdgeSub(int u, int v, int flow)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].flow = flow;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline void addEdge(int u, int v, int flow)
{
    addEdgeSub(u, v, flow);
    addEdgeSub(v, u, 0);
}

int queue[MAXN];

bool bfs(int start, int end)
{
    int front = 0, rear = 0;
    memset(depth, -1, sizeof(depth));
    queue[front++] = start;
    depth[start] = 0;
    while(rear < front)
    {
        int k = queue[rear++];
        for(int i=head[k];i!=-1;i=edge[i].next)
        {
            int to = edge[i].v;
            if(-1 == depth[to] && edge[i].flow > 0)
            {
                depth[to] = depth[k] + 1;
                queue[front++] = to;
            }
        }
    }
    return -1 != depth[end];
}

int dinic(int start, int end, int sum)
{
    if(start == end)
    {
        return sum;
    }
    int temp = sum;
    for(int i=head[start];i!=-1 && sum;i=edge[i].next)
    {
        if(edge[i].flow > 0 && depth[edge[i].v] == depth[start] + 1)
        {
            int a = dinic(edge[i].v, end, min(sum, edge[i].flow));
            edge[i].flow -= a;
            edge[i^1].flow += a;
            sum -= a;
        }
    }
    if(temp == sum)
    {
        depth[start] = -1;
    }
    return temp - sum;
}

int maxFlow(int start, int end)
{
    int result = 0;
    while(bfs(start, end))
    {
        result += dinic(start, end, INF);
    }
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        memset(d, 0, sizeof(d));
        int src = 0, des = n + 1;
        int sum = 0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d", &b[i][j]);
                d[j] += b[i][j];
                addEdge(i, j, b[i][j]);
            }
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &c[i]);
            addEdge(src, i, c[i]);
            addEdge(i, des, d[i]);
            sum += d[i];
        }
        printf("%d\n", sum - maxFlow(src, des));
    }
    return 0;
}
