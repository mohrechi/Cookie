#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int INF = 0x7fffffff;

int n, value[MAXN], stamp;
int size[MAXN], father[MAXN], son[MAXN], depth[MAXN];
int top[MAXN], idx[MAXN], pos[MAXN];

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

void initRelation(int u, int f = -1, int d = 0)
{
    size[u] = 1;
    father[u] = f;
    son[u] = 0;
    depth[u] = d;
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
    pos[stamp] = u;
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

struct TreeNode
{
    int l, r, lc, rc;
    int sum, maxL, maxR, opt;
    int lazy;
    inline int mid() const
    {
        return (l + r) >> 1;
    }
    inline int size() const
    {
        return r - l + 1;
    }
} node[MAXN * 3];
int nodeNum, tree[MAXN];

inline void combine(int &sum, int &maxL, int &maxR, int &opt, const int &sumL, const int &maxLL, const int &maxRL, const int &optL, const int &sumR, const int &maxLR, const int &maxRR, const int &optR)
{
    sum = sumL + sumR;
    maxL = max(maxLL, sumL + maxLR);
    maxR = max(maxRR, sumR + maxRL);
    opt = max(max(optL, optR), maxRL + maxLR);
}

inline void pushUp(const int &x)
{
    int L = node[x].lc;
    int R = node[x].rc;
    combine(node[x].sum, node[x].maxL, node[x].maxR, node[x].opt, node[L].sum, node[L].maxL, node[L].maxR, node[L].opt, node[R].sum, node[R].maxL, node[R].maxR, node[R].opt);
}

inline void pushDown(const int &x)
{
    if (node[x].lazy != INF)
    {
        int L = node[x].lc;
        int R = node[x].rc;
        int lazy = node[x].lazy;
        node[L].sum = lazy * node[L].size();
        node[L].opt = max(lazy, node[L].sum);
        node[L].maxL = node[L].opt;
        node[L].maxR = node[L].opt;
        node[L].lazy = lazy;
        node[R].sum = lazy * node[R].size();
        node[R].opt = max(lazy, node[R].sum);
        node[R].maxL = node[R].opt;
        node[R].maxR = node[R].opt;
        node[R].lazy = lazy;
        node[x].lazy = INF;
    }
}

int build(int l, int r)
{
    int x = nodeNum++;
    node[x].l = l;
    node[x].r = r;
    node[x].lazy = INF;
    if (l == r)
    {
        node[x].sum = value[pos[l]];
        node[x].maxL = value[pos[l]];
        node[x].maxR = value[pos[l]];
        node[x].opt = value[pos[l]];
        return x;
    }
    int mid = node[x].mid();
    node[x].lc = build(l, mid);
    node[x].rc = build(mid + 1, r);
    pushUp(x);
    return x;
}

void update(int x, int l, int r, int val)
{
    if (node[x].l == l && node[x].r == r)
    {
        node[x].sum = val * node[x].size();
        node[x].opt = max(val, node[x].sum);
        node[x].maxL = node[x].opt;
        node[x].maxR = node[x].opt;
        node[x].lazy = val;
        return;
    }
    pushDown(x);
    int mid = node[x].mid();
    if (r <= mid)
    {
        update(node[x].lc, l, r, val);
    }
    else if (l > mid)
    {
        update(node[x].rc, l, r, val);
    }
    else
    {
        update(node[x].lc, l, mid, val);
        update(node[x].rc, mid + 1, r, val);
    }
    pushUp(x);
}

void query(int x, int l, int r, int &sum, int &maxL, int &maxR, int &opt)
{
    if (node[x].l == l && node[x].r == r)
    {
        sum = node[x].sum;
        maxL = node[x].maxL;
        maxR = node[x].maxR;
        opt = node[x].opt;
        return;
    }
    pushDown(x);
    int mid = node[x].mid();
    if (r <= mid)
    {
        query(node[x].lc, l, r, sum, maxL, maxR, opt);
    }
    else if (l > mid)
    {
        query(node[x].rc, l, r, sum, maxL, maxR, opt);
    }
    else
    {
        int sumL, maxLL, maxRL, optL;
        int sumR, maxLR, maxRR, optR;
        query(node[x].lc, l, mid, sumL, maxLL, maxRL, optL);
        query(node[x].rc, mid + 1, r, sumR, maxLR, maxRR, optR);
        combine(sum, maxL, maxR, opt, sumL, maxLL, maxRL, optL, sumR, maxLR, maxRR, optR);
    }
}

int query(int x, int l, int r)
{
    int sum, maxL, maxR, opt;
    query(x, l, r, sum, maxL, maxR, opt);
    return opt;
}

void buildTree(int u, int f)
{
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f && v != son[u])
        {
            buildTree(v, u);
        }
    }
    if (son[u])
    {
        buildTree(son[u], u);
    }
    else
    {
        tree[idx[top[u]]] = build(idx[top[u]], idx[u]);
    }
}

void buildTree()
{
    nodeNum = 0;
    buildTree(1, -1);
}

inline void queryChainSub(int &sumC, int &maxLC, int &maxRC, int &optC, const int &sumN, const int &maxLN, const int &maxRN, const int &optN)
{
    int sum, maxL, maxR, opt;
    if (INF == sumC)
    {
        sum = sumN;
        maxL = maxLN;
        maxR = maxRN;
        opt = optN;
    }
    else
    {
        combine(sum, maxL, maxR, opt, sumN, maxLN, maxRN, optN, sumC, maxLC, maxRC, optC);
    }
    sumC = sum;
    maxLC = maxL;
    maxRC = maxR;
    optC = opt;
}

int queryChain(int u, int v)
{
    int sum, maxL, maxR, opt;
    int sumL = INF, maxLL, maxRL, optL;
    int sumR = INF, maxLR, maxRR, optR;
    int sumT, maxLT, maxRT, optT;
    while (true)
    {
        if (top[u] == top[v])
        {
            if (idx[u] >= idx[v])
            {
                query(tree[idx[top[u]]], idx[v], idx[u], sumT, maxLT, maxRT, optT);
                queryChainSub(sumL, maxLL, maxRL, optL, sumT, maxLT, maxRT, optT);
            }
            else
            {
                query(tree[idx[top[v]]], idx[u], idx[v], sumT, maxLT, maxRT, optT);
                queryChainSub(sumR, maxLR, maxRR, optR, sumT, maxLT, maxRT, optT);
            }
            break;
        }
        if (depth[top[u]] >= depth[top[v]])
        {
            query(tree[idx[top[u]]], idx[top[u]], idx[u], sumT, maxLT, maxRT, optT);
            queryChainSub(sumL, maxLL, maxRL, optL, sumT, maxLT, maxRT, optT);
            u = father[top[u]];
        }
        else
        {
            query(tree[idx[top[v]]], idx[top[v]], idx[v], sumT, maxLT, maxRT, optT);
            queryChainSub(sumR, maxLR, maxRR, optR, sumT, maxLT, maxRT, optT);
            v = father[top[v]];
        }
    }
    if (INF == sumR)
    {
        return optL;
    }
    if (INF == sumL)
    {
        return optR;
    }
    combine(sum, maxL, maxR, opt, sumL, maxRL, maxLL, optL, sumR, maxLR, maxRR, optR);
    return opt;
}

void updateChain(int u, int v, int val)
{
    while (true)
    {
        if (top[u] == top[v])
        {
            int left = idx[u];
            int right = idx[v];
            if (left > right)
            {
                swap(left, right);
            }
            update(tree[idx[top[u]]], left, right, val);
            break;
        }
        if (depth[top[u]] >= depth[top[v]])
        {
            update(tree[idx[top[u]]], idx[top[u]], idx[u], val);
            u = father[top[u]];
        }
        else
        {
            update(tree[idx[top[v]]], idx[top[v]], idx[v], val);
            v = father[top[v]];
        }
    }
}

int main()
{
    int u, v, m, o, c;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &value[i]);
        }
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        initHeavy();
        buildTree();
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d%d", &o, &u, &v);
            if (1 == o)
            {
                printf("%d\n", max(0, queryChain(u, v)));
            }
            else
            {
                scanf("%d", &c);
                updateChain(u, v, c);
            }
        }
    }
    return 0;
}
