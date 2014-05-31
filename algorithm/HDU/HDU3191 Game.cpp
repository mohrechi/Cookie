#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 1000;

struct Edge
{
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int getSG(int u)
{
    int sg = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (u == 0)
        {
            sg ^= getSG(v);
        }
        else
        {
            sg ^= getSG(v) + 1;
        }
    }
    return sg;
}

int main()
{
    int n, a;
    while (~scanf("%d", &n))
    {
        clearEdge();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            addEdge(a == -1 ? 0 : a + 1, i);
        }
        puts(getSG(0) ? "YES" : "NO");
    }
    return 0;
}
