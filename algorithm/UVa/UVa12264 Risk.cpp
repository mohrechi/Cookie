#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXM = MAXN * MAXN * 4;
const int INF = 0x7fffffff;

int n;
int a[MAXN];
bool isBorder[MAXN];
int borderNum, insideNum;
char graph[MAXN][MAXN];

struct Edge
{
    int u, v, f;
    int next;
} edge[MAXM];
int head[MAXN * 2], edgeNum;
int src, dst;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int f)
{
    edge[edgeNum].u = u;
    edge[edgeNum].v = v;
    edge[edgeNum].f = f;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int f)
{
    addEdgeSub(u, v, f);
    addEdgeSub(v, u, 0);
}

int queue[MAXN * 4];
int mark[MAXN * 4];

bool bfs()
{
    int front = 0, rear = 1;
    memset(mark, -1, sizeof(mark));
    queue[0] = src;
    mark[src] = 0;
    while (front < rear)
    {
        int u = queue[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (edge[i].f && mark[v] == -1)
            {
                mark[v] = mark[u] + 1;
                queue[rear++] = v;
                if (v == dst)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int dfs(int u, int flow)
{
    if (u == dst)
    {
        return flow;
    }
    int ret = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        int f = 0;
        if (mark[v] == mark[u] + 1 && edge[i].f && (f = dfs(v, min(flow - ret, edge[i].f))))
        {
            edge[i].f -= f;
            edge[i ^ 1].f += f;
            ret += f;
            if (ret == flow)
            {
                return ret;
            }
        }
    }
    if (ret == 0)
    {
        mark[u] = -1;
    }
    return ret;
}

int dinic()
{
    int ans = 0;
    while (bfs())
    {
        int temp = 0;
        while (temp = dfs(src, INF))
        {
            ans += temp;
        }
    }
    return ans;
}

void buildGraph(int mid)
{
    src = 0;
    dst = n + n + 1;
    clearEdge();
    for (int i = 1; i <= n; ++i)
    {
        if (a[i])
        {
            addEdge(src, i, a[i]);
            addEdge(i, i + n, a[i]);
            for (int j = 1; j <= n; ++j)
            {
                if (graph[i][j] == 'Y')
                {
                    if (a[j])
                    {
                        addEdge(i + n, j, a[i]);
                    }
                }
            }
            if (isBorder[i])
            {
                addEdge(i, dst, mid);
            }
            else
            {
                addEdge(i, dst, 1);
            }
        }
    }
}

bool judge(int mid)
{
    buildGraph(mid);
    return dinic() == borderNum * mid + insideNum;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int left = 1, right = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            right += a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", graph[i] + 1);
        }
        memset(isBorder, false, sizeof(isBorder));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (graph[i][j] == 'Y')
                {
                    if (a[j] == 0)
                    {
                        isBorder[i] = true;
                        break;
                    }
                }
            }
        }
        borderNum = 0;
        insideNum = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i])
            {
                if (isBorder[i])
                {
                    ++borderNum;
                }
                else
                {
                    ++insideNum;
                }
            }
        }
        int ans = 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (judge(mid))
            {
                left = mid + 1;
                ans = max(ans, mid);
            }
            else
            {
                right = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
