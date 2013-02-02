#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Edge
{
    int v, next;
} edge[MAXN * 2];
int edgeNumber, head[MAXN];

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int w[MAXN], visit[MAXN];
int value[MAXN];
int father[MAXN];
int depth[MAXN];

void dfs(int x, int fa, int weight, int d)
{
    if(!visit[x])
    {
        visit[x] = true;
        father[x] = fa;
        value[x] = w[x] ^ weight;
        depth[x] = d;
        for(int i=head[x];i!=-1;i=edge[i].next)
        {
            dfs(edge[i].v, x, value[x], d + 1);
        }
    }
}

int findFather(int x, int y)
{
    while(x != y)
    {
        if(depth[x] > depth[y])
        {
            x = father[x];
        }
        else if(depth[x] < depth[y])
        {
            y = father[y];
        }
        else
        {
            x = father[x];
            y = father[y];
        }
    }
    return x;
}

int main()
{
    int n, q;
    int u, v;
    while(~scanf("%d%d", &n, &q))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &w[i]);
        }
        clearEdge();
        for(int i=1;i<n;++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        memset(visit, false, sizeof(visit));
        dfs(1, -1, 0, 0);
        for(int i=0;i<q;++i)
        {
            scanf("%d%d", &u, &v);
            int f = findFather(u, v);
            int ans;
            if(f == 1)
            {
                ans = value[u] ^ value[v] ^ value[1];
            }
            else
            {
                ans = value[u] ^ value[v] ^ value[f] ^ value[father[f]];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
