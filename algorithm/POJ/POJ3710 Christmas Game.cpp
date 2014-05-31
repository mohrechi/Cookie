#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 500 * 2 + 10;

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

inline void addEdgeSub(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v)
{
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

int dfn[MAXN], low[MAXN];
int stack[MAXN], top, timeStamp;
bool visit[MAXN];
int sg[MAXN], inLoop[MAXN];

void tarjan(int u, int f)
{
    dfn[u] = low[u] = timeStamp++;
    visit[u] = true;
    stack[top++] = u;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == f)
        {
            continue;
        }
        if (dfn[v] == -1)
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (visit[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        int t;
        int cnt = 0;
        do
        {
            t = stack[--top];
            visit[t] = false;
            if (t != u)
            {
                inLoop[t] = true;
            }
            ++cnt;
        }
        while (t != u);
        if (cnt > 1)
        {
            sg[u] ^= cnt & 1;
        }
    }
}

int getSG(int u, int f)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f && !inLoop[v])
        {
            sg[u] ^= getSG(v, u) + 1;
        }
    }
    return sg[u];
}

int main()
{
    int n, m, k, u, v;
    while (~scanf("%d", &n))
    {
        int ans = 0;
        while (n--)
        {
            scanf("%d%d", &m, &k);
            clearEdge();
            while (k--)
            {
                scanf("%d%d", &u, &v);
                addEdge(u, v);
            }
            top = timeStamp = 0;
            memset(visit, false, sizeof(visit));
            memset(dfn, -1, sizeof(dfn));
            memset(low, -1, sizeof(low));
            memset(sg, 0, sizeof(sg));
            memset(inLoop, false, sizeof(inLoop));
            tarjan(1, -1);
            ans ^= getSG(1, -1);
        }
        puts(ans ? "Sally" : "Harry");
    }
    return 0;
}
