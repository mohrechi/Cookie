#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 200005;

int n, m;
struct Edge
{
    int v, w, s, next;
    bool operator < (const Edge &other) const
    {
        if(s == other.s)
        {
            return w > other.w;
        }
        return s > other.s;
    }
}edge[MAXM], node[MAXM], sm[MAXM];
int edgeNumber, nodeNumber, head[MAXN];
int smNumber;

inline void initEdge()
{
    edgeNumber = nodeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w, int s)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].s = s;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline void addNode(int u, int v, int w, int s)
{
    node[nodeNumber].next = u;
    node[nodeNumber].v = v;
    node[nodeNumber].w = w;
    node[nodeNumber].s = s;
    ++ nodeNumber;
}

int visit[MAXN];

void dfs(int x)
{
    if(!visit[x])
    {
        visit[x] = true;
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            dfs(edge[i].v);
        }
    }
}

bool judge()
{
    memset(visit, false, sizeof(visit));
    dfs(1);
    for(int i=1;i<=n;++i)
    {
        if(!visit[i])
        {
            return false;
        }
    }
    return true;
}

int father[MAXN];

void init()
{
    for(int i=1;i<=n;++i)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void combine(int x, int y)
{
    x = find(x);
    y = find(y);
    father[x] = y;
}

long long big()
{
    long long b = 0;
    long long bb = 0;
    init();
    for(int i=0;i<m;++i)
    {
        if(node[i].s == 0)
        {
            break;
        }
        b += node[i].w;
        int u = node[i].next;
        int v = node[i].v;
        if(find(u) != find(v))
        {
            bb += node[i].w;
            combine(u, v);
        }
    }
    return b - bb;
}

void dfs2(int x, int color)
{
    if(visit[x] == -1)
    {
        visit[x] = color;
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            if(edge[i].s == 1)
            {
                dfs2(edge[i].v, color);
            }
        }
    }
}

void sink()
{
    smNumber = 0;
    for(int i=nodeNumber-1;i>=0;--i)
    {
        if(node[i].s == 1)
        {
            break;
        }
        int u = node[i].next;
        int v = node[i].v;
        if(visit[u] != visit[v])
        {
            sm[smNumber].next = visit[u];
            sm[smNumber].v = visit[v];
            sm[smNumber].w = node[i].w;
            ++ smNumber;
        }
    }
}

long long small()
{
    memset(visit, -1, sizeof(visit));
    int color = 1;
    for(int i=1;i<=n;++i)
    {
        dfs2(i, color++);
    }
    sink();
    init();
    long long s = 0;
    for(int i=0;i<smNumber;++i)
    {
        int u = sm[i].next;
        int v = sm[i].v;
        if(find(u) != find(v))
        {
            s += sm[i].w;
            combine(u, v);
        }
    }
    return s;
}

int main()
{
    int u, v, w, s;
    while(~scanf("%d%d", &n, &m))
    {
        initEdge();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d%d", &u, &v, &w, &s);
            addNode(u, v, w, s);
            addEdge(u, v, w, s);
            addEdge(v, u, w, s);
        }
        if(judge())
        {
            sort(node, node + nodeNumber);
            long long ans = big();
            ans += small();
            printf("%lld\n", ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
