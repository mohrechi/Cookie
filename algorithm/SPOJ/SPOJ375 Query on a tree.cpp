#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

int n, weight[MAXN];

int stamp;
int size[MAXN], depth[MAXN], father[MAXN], son[MAXN], mark[MAXN];
int top[MAXN], idx[MAXN], map[MAXN];

struct TreeNode
{
    int l, r, w;
} tree[MAXN * 3];

inline void pushUp(int x)
{
    tree[x].w = max(tree[x << 1].w, tree[(x << 1) + 1].w);
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
    {
        tree[x].w = weight[map[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
    pushUp(x);
}

void update(int x, int pos, int value)
{
    if (tree[x].l == tree[x].r)
    {
        tree[x].w = value;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        update((x << 1), pos, value);
    }
    else
    {
        update((x << 1) + 1, pos, value);
    }
    pushUp(x);
}

int query(int x, int l, int r)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        return tree[x].w;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        return query(x << 1, l, r);
    }
    if (l > mid)
    {
        return query((x << 1) + 1, l, r);
    }
    return max(query(x << 1, l, mid), query((x << 1) + 1, mid + 1, r));
}

struct Edge
{
    int v, id, next;
} edge[MAXN * 2];
int edgeNum, head[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int id)
{
    edge[edgeNum].v = v;
    edge[edgeNum].id = id;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int id)
{
    addEdgeSub(u, v, id);
    addEdgeSub(v, u, id);
}

void initRelation(int u, int f = -1, int d = 0)
{
    size[u] = 1;
    depth[u] = d;
    father[u] = f;
    son[u] = 0;
    top[u] = u;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            initRelation(v, u, d + 1);
            if (size[v] > size[son[u]])
            {
                son[u] = v;
            }
            size[u] += size[v];
            mark[v] = edge[i].id;
        }
    }
}

void initIndex(int u, int f = -1)
{
    if (son[u])
    {
        top[son[u]] = top[u];
        idx[mark[son[u]]] = ++stamp;
        map[stamp] = mark[son[u]];
        initIndex(son[u], u);
    }
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f && v != son[u])
        {
            idx[edge[i].id] = ++stamp;
            map[stamp] = edge[i].id;
            initIndex(v, u);
        }
    }
}

void initHeavy()
{
    stamp = 0;
    initRelation(1);
    initIndex(1);
}

void queryTree(int u, int v)
{
    int ret = 0;
    while (u != v)
    {
        int tu = top[u];
        int tv = top[v];
        if (tu == tv)
        {
            int left, right;
            if (depth[u] <= depth[v])
            {
                left = idx[mark[son[u]]];
                right = idx[mark[v]];
            }
            else
            {
                left = idx[mark[son[v]]];
                right = idx[mark[u]];
            }
            ret = max(ret, query(1, left, right));
            break;
        }
        else if (depth[tu] > depth[tv] || (depth[tu] == depth[tv] && depth[u] > depth[v]))
        {
            int right = idx[mark[u]];
            int left = idx[mark[son[tu]]];
            if (u == tu)
            {
                left = right;
                u = 1 == u ? 1 : father[u];
            }
            else
            {
                u = top[u];
            }
            ret = max(ret, query(1, left, right));
        }
        else
        {
            int right = idx[mark[v]];
            int left = idx[mark[son[tv]]];
            if (v == tv)
            {
                left = right;
                v = 1 == v ? 1 : father[v];
            }
            else
            {
                v = top[v];
            }
            ret = max(ret, query(1, left, right));
        }
    }
    printf("%d\n", ret);
}

int main()
{
    int T, u, v;
    char op[8];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &weight[i]);
            addEdge(u, v, i);
        }
        initHeavy();
        build(1, 1, n - 1);
        while (true)
        {
            scanf("%s", op);
            if ('D' == *op)
            {
                break;
            }
            scanf("%d%d", &u, &v);
            if ('C' == *op)
            {
                update(1, idx[u], v);
            }
            else
            {
                queryTree(u, v);
            }
        }
    }
    return 0;
}
