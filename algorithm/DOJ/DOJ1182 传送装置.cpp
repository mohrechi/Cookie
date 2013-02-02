#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXM = MAXN * MAXN  * 2;
const int INF = 0x3f3f3f3f;

int n, m, s;
struct Edge
{
    int u, v, f, next;
} edge[MAXM];
int head[MAXN], edgeNumber;
int source, destination;

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
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
    addEdgeSub(v, u, 0);
}

int queue[MAXM];
int mark[MAXM];

bool bfs()
{
    memset(mark, -1, sizeof(mark));
    int front = 0, rear = 1;
    queue[0] = source;
    mark[source] = 0;
    while(front < rear)
    {
        int u = queue[front++];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(edge[i].f && mark[v] == -1)
            {
                mark[v] = mark[u] + 1;
                queue[rear++] = v;
                if(v == destination)
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
    if(u == destination)
    {
        return flow;
    }
    int ret = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        int f = 0;
        if(mark[v] == mark[u] + 1 && edge[i].f && (f = dfs(v, min(flow - ret, edge[i].f))))
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
    if(ret == 0)
    {
        mark[u]=-1;
    }
    return ret;
}

int dinic()
{
    int ans = 0;
    while(bfs())
    {
        int temp = 0;
        while(temp = dfs(source, INF))
        {
            ans += temp;
        }
    }
    return ans;
}

int main()
{
    int u, v, w;
    while(~scanf("%d%d%d", &n, &m, &s))
    {
        source = 0;
        destination = n + 1;
        clearEdge();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            if(u == s)
            {
                u = source;
            }
            if(v == s)
            {
                v = destination;
            }
            addEdge(u, v, w);
        }
        int ans = dinic();
        if(ans == 0)
        {
            printf("Poor Sue\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}
