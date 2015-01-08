#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

struct Edge
{
    int index, v, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

void initEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

void addEdgeSub(int index, int u, int v)
{
    edge[edgeNum].index = index;
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void addEdge(int index, int u, int v)
{
    addEdgeSub(index, u, v);
    addEdgeSub(index, v, u);
}

int n, l[MAXN];
double t[MAXN];

int dfs(int u, int e)
{
    int m = 1;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int index = edge[i].index;
        if (index == e)
        {
            continue;
        }
        m += dfs(edge[i].v, index);
    }
    t[e] = (double)m * (n - m);
    return m;
}

int main()
{
    int a, b;
    scanf("%d", &n);
    initEdge();
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d%d", &a, &b, &l[i]);
        addEdge(i, a, b);
    }
    dfs(1, 0);
    double sum = 0.0;
    for (int i = 1; i < n; ++i)
    {
        sum += t[i] * l[i];
    }
    double constant = 3.0 / ((double)n * (n - 1) / 2);
    int q, r, w;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &r, &w);
        sum -= t[r] * (l[r] - w);
        l[r] = w;
        printf("%f\n", sum * constant);
    }
    return 0;
}
