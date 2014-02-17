#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m;
struct TreeNode
{
    int l, r;
} tree[MAXN * 3];
int sorted[MAXN];
int value[20][MAXN];
int leftNum[20][MAXN];

void build(int x, int l, int r, int d)
{
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    int same = mid - l + 1;
    for (int i = l; i <= r; ++i)
    {
        if(value[d][i] < sorted[mid])
        {
            --same;
        }
    }
    int pLeft = l, pRight = mid + 1;
    for (int i = l; i <= r; ++i)
    {
        leftNum[d][i] = i == l ? 0 : leftNum[d][i - 1];
        if(value[d][i] < sorted[mid])
        {
            value[d + 1][pLeft++] = value[d][i];
            ++leftNum[d][i];
        }
        else if(value[d][i] > sorted[mid])
        {
            value[d + 1][pRight++] = value[d][i];
        }
        else if(same)
        {
            value[d + 1][pLeft++] = value[d][i];
            ++leftNum[d][i];
            --same;
        }
        else
        {
            value[d + 1][pRight++] = value[d][i];
        }
    }
    build(x << 1, l, mid, d + 1);
    build((x << 1) + 1, mid + 1, r, d + 1);
}

int query(int x, int l, int r, int d, int k)
{
    if (l == r)
    {
        return value[d][l];
    }
    int lLeft = l == tree[x].l ? 0 : leftNum[d][l-1];
    int rLeft = leftNum[d][r];
    int totalLeft = rLeft - lLeft;
    if(k <= totalLeft)
    {
        return query(x << 1, tree[x].l + lLeft, tree[x].l + rLeft - 1, d + 1, k);
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    int lRight = l - tree[x].l - lLeft;
    int totalRight = r - l + 1 - totalLeft;
    return query((x << 1) + 1, mid + lRight + 1, mid + lRight + totalRight, d + 1, k - totalLeft);
}

struct Edge
{
    int v, next;
} edge[MAXN * 2];
int edgeNum, head[MAXN];

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

int stamp;
int idx[MAXN], ori[MAXN], deep[MAXN];
map<int, int> back;

void dfs(int u = 1, int f = -1)
{
    idx[u] = stamp;
    ori[stamp] = u;
    deep[u] = stamp;
    ++stamp;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            dfs(v, u);
            deep[u] = max(deep[u], deep[v]);
        }
    }
}

int main()
{
    int u, v;
    while (~scanf("%d", &n))
    {
        back.clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &value[0][i]);
            back[value[0][i]] = i + 1;
        }
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        stamp = 0;
        dfs();
        for (int i = 0; i < n; ++i)
        {
            sorted[i] = value[0][ori[i] - 1];
        }
        for (int i = 0; i < n; ++i)
        {
            value[0][i] = sorted[i];
        }
        sort(sorted, sorted + n);
        build(1, 0, n - 1, 0);
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", back[query(1, idx[u], deep[u], 0, v)]);
        }
    }
    return 0;
}
