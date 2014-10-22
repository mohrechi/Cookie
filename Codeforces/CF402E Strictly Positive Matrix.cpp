#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000 + 10;

int n;
struct Edge
{
    int v, next;
} edge[MAXN * MAXN];
int edgeNum, head[MAXN];
int dfn[MAXN], low[MAXN], color, timeStamp;
int stack[MAXN], top;
bool visit[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void dfs(int u)
{
    dfn[u] = low[u] = ++timeStamp;
    visit[u] = true;
    stack[top++] = u;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (-1 == dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (visit[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        ++color;
        int x;
        do
        {
            x = stack[--top];
            visit[x] = false;
        }
        while (u != x);
    }
}

int main()
{
    int x;
    scanf("%d", &n);
    clearEdge();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &x);
            if (x)
            {
                addEdge(i, j);
            }
        }
    }
    memset(dfn, -1, sizeof(dfn));
    for (int i = 1; i <= n; ++i)
    {
        if (-1 == dfn[i])
        {
            dfs(i);
        }
    }
    puts(color == 1 ? "YES" : "NO");
    return 0;
}
