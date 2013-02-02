#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

//#define Enumerate  //157ms
#define Dichotomy  //125ms

static const int MAXN = 55;
static const int MAXM = 105;
static const int INF = 1000000000;

int n;
int availTime[MAXN];
bool avail[MAXN][50];
int maxTime, minTime;
int source, destination;

struct Node
{
    int u, v;
}node[205];
int nodeNumber;

bool operator < (const Node &a, const Node &b)
{
    if(a.u == b.u)
    {
        return a.v < b.v;
    }
    return a.u < b.u;
}

inline void addNode(int u, int v)
{
    node[nodeNumber].u = u;
    node[nodeNumber++].v = v;
}

struct Edge
{
    int u, v, f, next;
}edge[MAXM * MAXM * 2];
int edgeNumber, head[MAXM];

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

inline int min(int x, int y)
{
    return x<y?x:y;
}

inline int max(int x, int y)
{
    return x>y?x:y;
}

void setAvail(int s, int t, bool avail[])
{
    if(s % 30)
    {
        s += 30 - (s % 30);
    }
    s = s / 30;
    t = t / 30;
    for(int k=s;k<t;++k)
    {
        avail[k] = true;
    }
}

void makeGraph(int time)
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    for(int i=n-1;i>=0;--i)
    {
        addEdge(source, 50 + i, availTime[i]);
        for(int j=0;j<48;++j)
        {
            if(avail[i][j])
            {
                addEdge(50 + i, j, 1);
            }
        }
    }
    for(int i=0;i<48;++i)
    {
        addEdge(i, destination, time);
    }
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
    source = 48, destination = 49;
    while(scanf("%d", &n), n)
    {
        minTime = INF;
        maxTime = 0;
        for(int i=0;i<n;++i)
        {
            int tnum, h, m, s, t;
            scanf("%d%d", &tnum, &availTime[i]);
            minTime = min(minTime, availTime[i]);
            maxTime = max(maxTime, availTime[i]);
            memset(avail[i], false, sizeof(avail[i]));
            availTime[i] /= 30;
            nodeNumber = 0;
            for(int j=0;j<tnum;++j)
            {
                scanf("%d:%d",&h,&m);
                s = (h * 60 + m) % 3600;
                scanf("%d:%d",&h,&m);
                t = (h * 60 + m) % 3600;
                if(s == t)
                {
                    addNode(0, 1440);
                }
                else if(s < t)
                {
                    addNode(s, t);
                }
                else
                {
                    addNode(s, 1440);
                    if(t) addNode(0, t);
                }
            }
            sort(node, node + nodeNumber);
            s = node[0].u;
            t = node[0].v;
            for(int j=1;j<nodeNumber;++j)
            {
                if(node[j].u > t)
                {
                    setAvail(s, t, avail[i]);
                    s = node[j].u;
                    t = node[j].v;
                }
                else
                {
                    t = max(t, node[j].v);
                }
            }
            setAvail(s, t, avail[i]);
        }
        int ans = 0;
        #if defined(Enumerate)
            makeGraph(1);
            for(int i=1;i<=n;++i)
            {
                if(dinic() == 48)
                {
                    ans = i;
                    for(int j=0;j<48;++j)
                    {
                        addEdge(j, destination, 1);
                    }
                }
                else
                {
                    break;
                }
            }
        #elif defined(Dichotomy)
            int left = 1, right = n;
            int mid;
            while(left <= right)
            {
                mid = (left + right) >> 1;
                makeGraph(mid);
                if(dinic() == 48 * mid)
                {
                    left = mid + 1;
                    ans = max(ans, mid);
                }
                else
                {
                    right = mid - 1;
                }
            }
        #endif
        printf("%d\n", ans);
    }
    return 0;
}
