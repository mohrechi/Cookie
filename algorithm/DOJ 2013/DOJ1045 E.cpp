#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 50005;

struct Edge
{
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNumber;

int n, m;
bool ans[MAXN];

int stack[MAXN], top, timeStamp;
bool inStack[MAXN];
int dfn[MAXN], low[MAXN];
int group[MAXN], groupNum;

void tarjan(int x)
{
    int t;
    dfn[x] = low[x] = timeStamp++;
    inStack[x] = true;
    stack[top++] = x;
    for (int i = head[x]; i != -1; i = edge[i].next)
    {
        t = edge[i].v;
        if (dfn[t] == -1)
        {
            tarjan(t);
            low[x] = min(low[x], low[t]);
        }
        else if (inStack[t])
        {
            low[x] = min(low[x], dfn[t]);
        }
    }
    if (dfn[x] == low[x])
    {
        groupNum = 0;
        do
        {
            t = stack[--top];
            group[groupNum++] = t;
            inStack[t] = false;
        }
        while (t != x);
        if (groupNum > 1)
        {
            for (int i = 0; i < groupNum; ++i)
            {
                ans[group[i]] = true;
            }
        }
    }
}

void solve()
{
    memset(ans, false, sizeof(ans));
    memset(inStack, false, sizeof(inStack));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    top = timeStamp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dfn[i] == -1)
        {
            tarjan(i);
        }
    }
}

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

int main()
{
    int u, v;
    while (~scanf("%d%d", &n, &m))
    {
        clearEdge();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        solve();
        for (int i = 1; i <= n; ++i)
        {
            if (ans[i])
            {
                printf("T\n");
            }
            else
            {
                printf("F\n");
            }
        }
        printf("\n");
    }
    return 0;
}
