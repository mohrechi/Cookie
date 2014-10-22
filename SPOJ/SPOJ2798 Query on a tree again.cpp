#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int n, m;
int stamp;
int size[MAXN], depth[MAXN], father[MAXN], son[MAXN];
int top[MAXN], idx[MAXN], map[MAXN];
bool black[MAXN];

struct TreeNode
{
    int l, r, w;
} tree[MAXN * 3];

inline void pushUp(int x)
{
    tree[x].w = tree[x << 1].w + tree[(x << 1) + 1].w;
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].w = 0;
    if (l == r)
    {
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
        tree[x].w += value;
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
    //printf("%d %d %d  %d %d  %d\n", x, tree[x].l, tree[x].r, l, r, tree[x].w);
    if (0 == tree[x].w)
    {
        return -1;
    }
    if (tree[x].l == tree[x].r)
    {
        if (tree[x].l >= l && tree[x].r <= r)
        {
            return tree[x].l;
        }
        return -1;
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
    int a = query(x, l, mid);
    if (-1 != a)
    {
        return a;
    }
    return query((x << 1) + 1, mid + 1, r);
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
    memset(black, false, sizeof(black));
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
        }
    }
}

void initIndex(int u, int f = -1)
{
    idx[u] = ++stamp;
    map[stamp] = u;
    if (son[u])
    {
        top[son[u]] = top[u];
        initIndex(son[u], u);
    }
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f && v != son[u])
        {
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

void updateTree(int u)
{
    if (black[u])
    {
        update(1, idx[u], -1);
        black[u] = false;
    }
    else
    {
        update(1, idx[u], 1);
        black[u] = true;
    }
}

int queryTree(int u)
{
    int ret = -1;
    if (black[u])
    {
        ret = u;
    }
    while (1 != u)
    {
        int tu = top[u];
        if (u == top[u])
        {
            u = father[u];
            if (black[u])
            {
                ret = u;
            }
        }
        else
        {
            int left = idx[top[u]];
            int right = idx[u];
            int v = query(1, left, right);
            if (-1 != v)
            {
                v = map[v];
                if (depth[v] < depth[u])
                {
                    if (-1 == ret)
                    {
                        ret = v;
                    }
                    else if (depth[v] < depth[ret])
                    {
                        ret = v;
                    }
                }
            }
            u = top[u];
        }
    }
    return ret;
}

int main()
{
    int u, v, w;
    scanf("%d%d", &n, &m);
    clearEdge();
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    initHeavy();
    build(1, 1, n);
    while (m--)
    {
        scanf("%d%d", &u, &v);
        if (0 == u)
        {
            updateTree(v);
        }
        else
        {
            printf("%d\n", queryTree(v));
        }
    }
    return 0;
}
