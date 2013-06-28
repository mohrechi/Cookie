#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int DIR_X[] = {0, 1};
const int DIR_Y[] = {1, 0};
const int INF = 0x3f3f3f3f;

int n, m;
int farm[MAXN][MAXN];
int src, dst;

struct Edge
{
    int u, v, f;
    int next;
} edge[MAXN * MAXN * 4];
int head[MAXN * MAXN], edgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int f)
{
    edge[edgeNum].u = u;
    edge[edgeNum].v = v;
    edge[edgeNum].f = f;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

bool isValid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

inline int getPos(int x, int y)
{
    return x * m + y;
}

void buildGraph()
{
    clearEdge();
    src = n * m;
    dst = n * m + 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (farm[i][j] == 1)
            {
                addEdge(src, getPos(i, j), INF);
                addEdge(getPos(i, j), src, 0);
            }
            else if (farm[i][j] == 2)
            {
                addEdge(getPos(i, j), dst, INF);
                addEdge(dst, getPos(i, j), 0);
            }
            for (int k = 0; k < 2; ++k)
            {
                int tx = i + DIR_X[k];
                int ty = j + DIR_Y[k];
                if (isValid(tx, ty))
                {
                    bool connect = true;
                    if (farm[i][j] == 1 && farm[tx][ty] == 1)
                    {
                        connect = false;
                    }
                    if (farm[i][j] == 2 && farm[tx][ty] == 2)
                    {
                        connect = false;
                    }
                    if (connect)
                    {
                        addEdge(getPos(i, j), getPos(tx, ty), 1);
                        addEdge(getPos(tx, ty), getPos(i, j), 1);
                    }
                }
            }
        }
    }
}

int queue[MAXN * MAXN];
int mark[MAXN * MAXN];

bool bfs()
{
    memset(mark, -1, sizeof(mark));
    int front = 0, rear = 1;
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
            if(ret == flow)
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

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &farm[i][j]);
            }
        }
        buildGraph();
        printf("%d\n", dinic());
    }
    return 0;
}
