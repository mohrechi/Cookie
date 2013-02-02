#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXM = MAXN * 3;

//#define DEBUG

#ifdef DEBUG
    #define DEBUG_BIN
    #define DEBUG_MAKE
#endif

int n, m;
int s, t1, t2;

struct Edge
{
    int u, v, w, f;
    int next;
} edge[MAXM * MAXM], originEdge[MAXM * MAXM];
int head[MAXM], originHead[MAXM], edgeNumber, originEdgeNumber;

inline void clearEdge()
{
    originEdgeNumber = 0;
    memset(originHead, -1, sizeof(originHead));
}

inline void addOriginEdgeSub(int u, int v, int w, int f)
{
    originEdge[originEdgeNumber].u = u;
    originEdge[originEdgeNumber].v = v;
    originEdge[originEdgeNumber].w = w;
    originEdge[originEdgeNumber].f = f;
    originEdge[originEdgeNumber].next = originHead[u];
    originHead[u] = originEdgeNumber ++;
}

inline void addOriginEdge(int u, int v, int w, int f)
{
    addOriginEdgeSub(u, v, w, f);
    addOriginEdgeSub(v, u, -w, 0);
}

inline void addEdgeSub(int u, int v, int w, int f)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].f = f;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline void addEdge(int u, int v, int w, int f)
{
    addEdgeSub(u, v, w, f);
    addEdgeSub(v, u, -w, 0);
}

inline void copyEdge()
{
    edgeNumber = originEdgeNumber;
    memcpy(head, originHead, sizeof(head));
    memcpy(edge, originEdge, sizeof(Edge) * originEdgeNumber);
}

int makeGraph(int x)
{
    copyEdge();
    addEdge(t1, t2, 0, x);
    #ifdef DEBUG_MAKE
    for(int i=s;i<=t2;++i)
    {
        printf("%d: ", i);
        for(int j=head[i];j!=-1;j=edge[j].next)
        {
            printf("(%d, %d %d) ", edge[j].v, edge[j].w, edge[j].f);
        }
        printf("\n");
    }
    #endif
}

int queue[MAXM];
int dist[MAXM];
int pre[MAXM];
bool visit[MAXM];

bool bfs()
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, 0x7f, sizeof(dist));
    visit[s] = true;
    dist[s] = 0;
    pre[s] = -1;
    queue[0] = s;
    bool flag = false;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            int f = edge[i].f;
            if(f)
            {
                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pre[v] = i;
                    if(!visit[v])
                    {
                        visit[v] = true;
                        flag |= v == t2;
                        queue[rear] = v;
                        if(++rear >= MAXM)
                        {
                            rear = 0;
                        }
                    }
                }
            }
        }
        visit[u] = false;
        if(++front >= MAXM)
        {
            front = 0;
        }
    }
    return flag;
}

int flow()
{
    int res = 0;
    while(bfs())
    {
        res += dist[t2];
        int temp = t2;
        int minFlow = 0x7f7f7f7f;
        while(pre[temp] != -1)
        {
            temp = pre[temp];
            minFlow = min(minFlow, edge[temp].f);
            temp = edge[temp].u;
        }
        temp = t2;
        while(pre[temp] != -1)
        {
            temp = pre[temp];
            edge[temp].f -= minFlow;
            edge[temp^1].f += minFlow;
            temp = edge[temp].u;
        }
    }
    return res;
}

bool judge()
{
    if(flow() > m)
    {
        return false;
    }
    if(edge[originEdgeNumber].f)
    {
        return false;
    }
    return true;
}

int main()
{
    int k, u, v, w;
    while(~scanf("%d%d", &n, &m))
    {
        s = 0;
        t1 = n + n + 1;
        t2 = n + n + 2;
        clearEdge();
        for(u=1;u<=n;++u)
        {
            addOriginEdge(s, u, 0, 1);
            scanf("%d", &k);
            while(k--)
            {
                scanf("%d%d", &v, &w);
                addOriginEdge(u, v + n, w, 1);
            }
            addOriginEdge(u + n, t1, 0, 1);
        }
        int l = 0, r = n;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            makeGraph(mid);
            #ifdef DEBUG_BIN
            printf("Two %d %d %d\n", l, r, mid);
            #endif
            if(judge())
            {
                l = mid + 1;
                ans = max(ans, mid);
            }
            else
            {
                r = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
