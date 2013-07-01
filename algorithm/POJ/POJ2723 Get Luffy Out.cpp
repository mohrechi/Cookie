#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2500;

int n, m;
int key[MAXN], door[MAXN][2], map[MAXN];
int stack[MAXN], top, timeStamp, color;
int dfn[MAXN], low[MAXN], belong[MAXN];
bool inStack[MAXN];

struct Edge
{
    int v, next;
}edge[MAXN * MAXN];
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

void build(int num)
{
    clearEdge();
    for(int i=0;i<num;++i)
    {
        addEdge(map[door[i][0]], map[door[i][1]] ^ 1);
        addEdge(map[door[i][1]], map[door[i][0]] ^ 1);
    }
}

void dfs(int u)
{
    dfn[u] = low[u] = timeStamp ++;
    inStack[u] = true;
    stack[top++] = u;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(dfn[v] == -1)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(inStack[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(dfn[u] == low[u])
    {
        int t;
        do
        {
            t = stack[--top];
            inStack[t] = false;
            belong[t] = color;
        }
        while(t != u);
        ++ color;
    }
}

void tarjan()
{
    memset(inStack, false, sizeof(inStack));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    timeStamp = color = top = 0;
    for(int i=0;i<(n<<1);++i)
    {
        if(dfn[i] == -1)
        {
            dfs(i);
        }
    }
}

bool judge(int num)
{
    build(num);
    tarjan();
    for(int i=0;i<n;++i)
    {
        if(belong[i<<1] == belong[(i<<1)+1])
        {
            return false;
        }
    }
    return true;
}

int solve()
{
    int left = 0, right = m;
    int mid, ans = 0;
    while(left <= right)
    {
        mid = (left + right) >> 1;
        if(judge(mid))
        {
            ans = max(ans, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%d%d", &n, &m), n || m)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &key[i<<1], &key[(i<<1)+1]);
            map[key[i<<1]] = i<<1;
            map[key[(i<<1)+1]] = (i<<1)+1;
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d%d", &door[i][0], &door[i][1]);
        }
        printf("%d\n", solve());
    }
    return 0;
}
