#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n;
struct Edge
{
    int v, w, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

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

int dfs(int u, int f, int in)
{
    int res = 0;
    int childNum = 0;
    int maxFlow = in;
    int totalFlow = in;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        int w = edge[i].w;
        if (v != f)
        {
            ++childNum;
            maxFlow = max(maxFlow, w);
            totalFlow += w;
            res += dfs(v, u, w);
        }
    }
    if (childNum)
    {
        if (maxFlow << 1 >= totalFlow)
        {
            res += maxFlow - in;
        }
        else
        {
            res += ((totalFlow + 1) >> 1) - in;
        }
    }
    return res;
}

int main()
{
    int T;
    int u, v, w;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &n);
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        printf("Case #%d: %d\n", t, dfs(1, 0, 0));
    }
    return 0;
}
