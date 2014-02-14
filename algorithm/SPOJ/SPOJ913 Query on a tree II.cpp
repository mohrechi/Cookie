#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;
const int MAXL = 15;

int n;
struct Edge
{
    int v, w, next;
} edge[MAXN * 2];
int edgeNum, head[MAXN];
int ancestor[MAXN][MAXL];
int depth[MAXN], dist[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w)
{
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

void dfs(int u, int f, int d, int t)
{
    dist[u] = d;
    depth[u] = t;
    ancestor[u][0] = f;
    for (int i = 1; ; ++i)
    {
        int a = ancestor[ancestor[u][i - 1]][i - 1];
        if (-1 == a)
        {
            break;
        }
        ancestor[u][i] = a;
    }
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            int w = edge[i].w;
            dfs(v, u, d + w, t + 1);
        }
    }
}

int lca(int u, int v)
{
    int i;
    while (u != v)
    {
        if (depth[u] >= depth[v])
        {
            for (i = 1; ; ++i)
            {
                int a = ancestor[u][i];
                if (-1 == a)
                {
                    break;
                }
                if (depth[a] < depth[v])
                {
                    break;
                }
            }
            u = ancestor[u][i - 1];
        }
        else
        {
            for (i = 1; ; ++i)
            {
                int a = ancestor[v][i];
                if (-1 == a)
                {
                    break;
                }
                if (depth[a] < depth[u])
                {
                    break;
                }
            }
            v = ancestor[v][i - 1];
        }
    }
    return u;
}

int getDist(int u, int v)
{
    int i;
    int du = dist[u];
    int dv = dist[v];
    int dc = dist[lca(u, v)];
    return du + dv - dc - dc;
}

int getTop(int u, int k)
{
    --k;
    while (k)
    {
        int i;
        for (i = 0; ; ++i)
        {
            int a = ancestor[u][i];
            if (-1 == a)
            {
                break;
            }
            if ((1 << i) > k)
            {
                break;
            }
        }
        k -= (1 << (i - 1));
        u = ancestor[u][i - 1];
    }
    return u;
}

int getKth(int u, int v, int k)
{
    int c = lca(u, v);
    int lu = depth[u] - depth[c] + 1;
    int lv = depth[v] - depth[c] + 1;
    if (lu >= k)
    {
        return getTop(u, k);
    }
    return getTop(v, lu + lv - k);
}

int main()
{
    int T, u, v, w;
    char op[8];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        memset(ancestor, -1, sizeof(ancestor));
        dfs(1, -1, 0, 0);
        while (true)
        {
            scanf("%s", op);
            if ('O' == op[1])
            {
                break;
            }
            if ('D' == *op)
            {
                scanf("%d%d", &u, &v);
                printf("%d\n", getDist(u, v));
            }
            else
            {
                scanf("%d%d%d", &u, &v, &w);
                printf("%d\n", getKth(u, v, w));
            }
        }
    }
    return 0;
}
