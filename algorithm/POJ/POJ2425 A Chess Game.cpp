#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;
const int MAXM = MAXN * MAXN;

struct Edge
{
    int v, next;
} edge[MAXM];
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

int sg[MAXN];

int getSG(int u)
{
    if (sg[u] != -1)
    {
        return sg[u];
    }
    bool visit[MAXN] = {false};
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        visit[getSG(edge[i].v)] = true;
    }
    for (int i = 0; ; ++i)
    {
        if (!visit[i])
        {
            return sg[u] = i;
        }
    }
}

int main()
{
    int n, m, v;
    while (~scanf("%d", &n))
    {
        clearEdge();
        for (int u = 0; u < n; ++u)
        {
            scanf("%d", &m);
            while (m--)
            {
                scanf("%d", &v);
                addEdge(u, v);
            }
        }
        memset(sg, -1, sizeof(sg));
        while (scanf("%d", &m), m)
        {
            int ans = 0;
            for (int i = 0; i < m; ++i)
            {
                scanf("%d", &v);
                ans ^= getSG(v);
            }
            puts(ans ? "WIN" : "LOSE");
        }
    }
    return 0;
}
