#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n;
struct Edge
{
    int v, w, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

double ans;

int dfs(int u, int f, int w)
{
    int count = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        int w = edge[i].w;
        if (f != v)
        {
            count += dfs(v, u, w);
        }
    }
    ans += w * (n - count - 1 + (n - count - 1.0) * count);
    return count + 1;
}

int main()
{
    int u, v, w;
    while (~scanf("%d", &n))
    {
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        ans = 0.0;
        dfs(1, -1, 0);
        printf("%.6lf\n", 2.0 * ans / n / n);
    }
    return 0;
}
