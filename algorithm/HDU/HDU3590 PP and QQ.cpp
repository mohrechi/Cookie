#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;

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

void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int getSG(int u, int f = -1)
{
    int sg = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            sg ^= getSG(v, u) + 1;
        }
    }
    return sg;
}

int main()
{
    int n, m, u, v;
    while (~scanf("%d", &n))
    {
        int cnt = 0, sg = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &m);
            clearEdge();
            for (int i = 1; i < m; ++i)
            {
                scanf("%d%d", &u, &v);
                addEdge(u, v);
                addEdge(v, u);
            }
            int temp = getSG(1);
            cnt += temp > 1;
            sg ^= temp;
        }
        puts((sg > 0 == cnt > 0) ? "PP" : "QQ");
    }
    return 0;
}
