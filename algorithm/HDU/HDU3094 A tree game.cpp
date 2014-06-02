#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

int n;
struct Edge
{
    int v, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

void addEdgeSub(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void addEdge(int u, int v)
{
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

int dfs(int u, int f = -1)
{
    int sg = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            sg ^= dfs(v, u) + 1;
        }
    }
    return sg;
}

int main()
{
    int T, u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        puts(dfs(1) ? "Alice" : "Bob");
    }
    return 0;
}
