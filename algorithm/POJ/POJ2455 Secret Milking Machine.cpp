#include <cstdio>
#include <cstring>
static const int MAXN = 210;
static const int MAXP = 40010;
static const int INF = 0x7FFFFFFF;

struct Node
{
    int u, v, w;
}node[MAXP];
int nodeNumber;
int n, p, t;
int maxLength;

struct Edge
{
    int u, v, f, next;
}edge[MAXP];
int edgeNumber, head[MAXN];

inline void addEdgeNode(int u, int v, int w)
{
    node[nodeNumber].u = u;
    node[nodeNumber].v = v;
    node[nodeNumber].w = w;
    ++ nodeNumber;
}

inline void addEdgeSub(int u, int v, int f)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].f = f;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline void addEdge(int u, int v, int f)
{
    addEdgeSub(u, v, f);
    addEdgeSub(v, u, f);
}

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int assistGraph[MAXN][MAXN];

void makeGraph(int mid)
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    memset(assistGraph, 0, sizeof(assistGraph));
    for(int i=0;i<nodeNumber;++i)
    {
        if(node[i].w <= mid)
        {
            ++ assistGraph[node[i].u][node[i].v];
            ++ assistGraph[node[i].v][node[i].u];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            if(assistGraph[i][j])
            {
                addEdge(i, j, assistGraph[i][j]);
            }
        }
    }
}

int depth[MAXN];
int queue[MAXN];

bool bfs()
{
    memset(depth, -1, sizeof(depth));
    int front = 0, rear = 1;
    queue[0] = 1;
    depth[1] = 0;
    while(front != rear)
    {
        int u = queue[front++];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(edge[i].f && depth[v] == -1)
            {
                depth[v] = depth[u] + 1;
                queue[rear++] = v;
                if(v == n)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int dfs(int u, int flow)
{
    if(u == n)
    {
        return flow;
    }
    int ret = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        int f = 0;
        if(depth[v] == depth[u] + 1 && edge[i].f && (f = dfs(v, min(flow - ret, edge[i].f))) )
        {
            edge[i].f -= f;
            edge[i^1].f += f;
            ret += f;
            if(ret == flow)
            {
                return ret;
            }
        }
    }
    return ret;
}

int dinic()
{
    int ans = 0;
    while(bfs())
    {
        int temp;
        while(temp = dfs(1, INF))
        {
            ans += temp;
        }
    }
    return ans;
}

int main()
{
    int u, v, w;
    while(~scanf("%d%d%d", &n, &p, &t))
    {
        nodeNumber = 0;
        maxLength = 0;
        for(int i=0;i<p;++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdgeNode(u, v, w);
            maxLength = max(maxLength, w);
        }
        int ans = maxLength;
        int left = 0, right = maxLength;
        int mid;
        while(left <= right)
        {
            mid = (left + right) >> 1;
            makeGraph(mid);
            if(dinic() >= t)
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
