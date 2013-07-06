#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 200005;

//#define DEBUG

int n, m;
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

int stack[MAXN], top;
int dfn[MAXN], low[MAXN];
int set[MAXN], setNum;
int timeStamp;
bool valid[MAXN];

void dfs(int u, int f)
{
    stack[++top] = u;
    dfn[u] = low[u] = ++timeStamp;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v == f)
        {
            continue;
        }
        if (dfn[v] == -1)
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        setNum = 0;
        do
        {
            set[setNum++] = stack[top];
        } while (stack[top--] != u);
        #ifdef DEBUG
        printf("    Set: ");
        for (int i = 0; i < setNum; ++i)
        {
            printf("%d ", set[i]);
        }
        printf("\n");
        #endif // DEBUG
        if (setNum > 2)
        {
            for (int i = 0; i < setNum; ++i)
            {
                valid[set[i]] = false;
            }
        }
    }
}

void tarjan()
{
    top = timeStamp = 0;
    memset(valid, true, sizeof(valid));
    memset(low, -1, sizeof(low));
    memset(dfn, -1, sizeof(dfn));
    for (int i = 1; i <= n; ++i)
    {
        if (dfn[i] == -1)
        {
            dfs(i, -1);
        }
    }
}

bool visit[MAXN];

int getNum(int u)
{
    int res = 1;
    visit[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (valid[v] && !visit[v])
        {
            res += getNum(v);
        }
    }
    return res;
}

int main()
{
    int T, u, v;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d", &n, &m);
        clearEdge();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        tarjan();
        #ifdef DEBUG
        for (int i = 1; i <= n; ++i)
        {
            printf("%d ", valid[i]);
        }
        printf("\n");
        #endif // DEBUG
        int ans = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= n; ++i)
        {
            if (valid[i] && !visit[i])
            {
                int num = getNum(i);
                ans += (num * (num - 1)) >> 1;
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
