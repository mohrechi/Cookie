#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

struct TreeNode
{
    int lc, rc;
    int sum;
} tree[MAXN * 30];
int treeNum, root[MAXN];

int build(int l, int r)
{
    int x = treeNum++;
    tree[x].sum = 0;
    if (l == r)
    {
        return x;
    }
    int mid = (l + r) >> 1;
    tree[x].lc = build(l, mid);
    tree[x].rc = build(mid + 1, r);
    return x;
}

int update(int o, int l, int r, int pos, int val)
{
    int x = treeNum++;
    tree[x] = tree[o];
    tree[x].sum += val;
    if (l == r)
    {
        return x;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        tree[x].lc = update(tree[o].lc, l, mid, pos, val);
    }
    else
    {
        tree[x].rc = update(tree[o].rc, mid + 1, r, pos, val);
    }
    return x;
}

int query(int a, int b, int c, int f, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int num = tree[tree[a].lc].sum + tree[tree[b].lc].sum - tree[tree[c].lc].sum - tree[tree[f].lc].sum;
    int mid = (l + r) >> 1;
    if (k <= num)
    {
        return query(tree[a].lc, tree[b].lc, tree[c].lc, tree[f].lc, l, mid, k);
    }
    return query(tree[a].rc, tree[b].rc, tree[c].rc, tree[f].rc, mid + 1, r, k - num);
}

int n, m;
int a[MAXN];
struct Node
{
    int val, index;
    bool operator <(const Node &node) const
    {
        return val < node.val;
    }
} node[MAXN];
int pos[MAXN];
int ancestor[MAXN][20];
int depth[MAXN];

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

inline void addEdgeSub(const int &u, const int &v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(const int &u, const int &v)
{
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

void dfs(int u, int f, int d)
{
    depth[u] = d;
    ancestor[u][0] = f;
    root[u] = update(root[f], 1, n, pos[u], 1);
    for (int i = 1; ; ++i)
    {
        int a = ancestor[ancestor[u][i - 1]][i - 1];
        if (0 == a)
        {
            break;
        }
        ancestor[u][i] = a;
    }
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            dfs(v, u, d + 1);
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] > depth[v])
    {
        swap(u, v);
    }
    if (depth[u] < depth[v])
    {
        int dist = depth[v] - depth[u];
        for (int i = 0; i < 20; ++i)
        {
            if (dist & (1 << i))
            {
                v = ancestor[v][i];
            }
        }
    }
    if (u != v)
    {
        for (int i = 19; i >= 0; --i)
        {
            if (ancestor[u][i] != ancestor[v][i])
            {
                u = ancestor[u][i];
                v = ancestor[v][i];
            }
        }
        u = ancestor[u][0];
    }
    return u;
}

int solve(int a, int b, int k)
{
    int c = lca(a, b);
    int f = ancestor[c][0];
    return query(root[a], root[b], root[c], root[f], 1, n, k);
}

void readInt(int &x)
{
    char ch;
    while (ch = getchar())
    {
        if (ch >= '0' && ch <= '9')
        {
            break;
        }
    }
    x = ch - '0';
    while (ch = getchar())
    {
        if (ch < '0' || ch > '9')
        {
            break;
        }
        x = x * 10 + ch - '0';
    }
}

int main()
{
    int u, v, k;
    readInt(n);
    readInt(m);
    for (int i = 1; i <= n; ++i)
    {
        readInt(a[i]);
        node[i].val = a[i];
        node[i].index = i;
    }
    sort(node + 1, node + 1 + n);
    pos[node[1].index] = 1;
    int j = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (node[i].val == node[i - 1].val)
        {
            pos[node[i].index] = j;
        }
        else
        {
            pos[node[i].index] = ++j;
            node[j] = node[i];
        }
    }
    clearEdge();
    for (int i = 1; i < n; ++i)
    {
        readInt(u);
        readInt(v);
        addEdge(u, v);
    }
    n = j;
    root[0] = build(1, n);
    dfs(1, 0, 0);
    while (m--)
    {
        readInt(u);
        readInt(v);
        readInt(k);
        printf("%d\n", node[solve(u, v, k)].val);
    }
    return 0;
}
