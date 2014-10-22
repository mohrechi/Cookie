#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
multiset<int> near[MAXN];

int stamp;
int size[MAXN], father[MAXN], son[MAXN];
int top[MAXN], idx[MAXN], pos[MAXN];
int whiteNum;
bool isWhite[MAXN];

inline int getD(int u)
{
    if (near[u].size() > 0)
    {
        return *near[u].begin();
    }
    return INF;
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

struct TreeNode
{
    int l, r, lc, rc;
    int minL, minR;
} node[MAXN * 3];
int nodeNum, tree[MAXN];

void initNode(int x)
{
    if (isWhite[pos[node[x].l]])
    {
        node[x].minL = node[x].minR = 0;
    }
    else
    {
        node[x].minL = node[x].minR = getD(node[x].l);
    }
}

void pushUp(int x)
{
    int L = node[x].lc;
    int R = node[x].rc;
    int mid = (node[x].l + node[x].r) >> 1;
    node[x].minL = min(node[L].minL, node[R].minL + mid + 1 - node[x].l);
    node[x].minR = min(node[R].minR, node[L].minR + node[x].r - mid);
}

int buildTree(int l, int r)
{
    int x = nodeNum++;
    node[x].l = l;
    node[x].r = r;
    if (l == r)
    {
        initNode(x);
        return x;
    }
    int mid = (l + r) >> 1;
    node[x].lc = buildTree(l, mid);
    node[x].rc = buildTree(mid + 1, r);
    pushUp(x);
    return x;
}

void updateTree(int x, int pos)
{
    if (node[x].l == node[x].r)
    {
        initNode(x);
        return;
    }
    int mid = (node[x].l + node[x].r) >> 1;
    if (pos <= mid)
    {
        updateTree(node[x].lc, pos);
    }
    else
    {
        updateTree(node[x].rc, pos);
    }
    pushUp(x);
}

int queryTreeL(int x, int l, int r)
{
    if (node[x].l == l && node[x].r == r)
    {
        return node[x].minL;
    }
    int mid = (node[x].l + node[x].r) >> 1;
    if (r <= mid)
    {
        return queryTreeL(node[x].lc, l, r);
    }
    if (l > mid)
    {
        return queryTreeL(node[x].rc, l, r);
    }
    int lmin = queryTreeL(node[x].lc, l, mid);
    int rmin = queryTreeL(node[x].rc, mid + 1, r);
    return min(lmin, rmin + mid + 1 - l);
}

int queryTreeR(int x, int l, int r)
{
    if (node[x].l == l && node[x].r == r)
    {
        return node[x].minR;
    }
    int mid = (node[x].l + node[x].r) >> 1;
    if (r <= mid)
    {
        return queryTreeR(node[x].lc, l, r);
    }
    if (l > mid)
    {
        return queryTreeR(node[x].rc, l, r);
    }
    int lmin = queryTreeR(node[x].lc, l, mid);
    int rmin = queryTreeR(node[x].rc, mid + 1, r);
    return min(rmin, lmin + r - mid);
}

void initRelation(int u, int f = -1)
{
    size[u] = 1;
    father[u] = f;
    son[u] = 0;
    top[u] = u;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            initRelation(v, u);
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

void buildTrees(int u, int f)
{
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f && v != son[u])
        {
            buildTrees(v, u);
        }
    }
    if (son[u])
    {
        buildTrees(son[u], u);
    }
    else
    {
        tree[idx[top[u]]] = buildTree(idx[top[u]], idx[u]);
    }
}

void buildTrees()
{
    buildTrees(1, -1);
}

void init()
{
    nodeNum = 0;
    clearEdge();
    whiteNum = 0;
    memset(isWhite, false, sizeof(isWhite));
    for (int i = 1; i <= n; ++i)
    {
        near[i].clear();
    }
}

void update(int u)
{
    if (isWhite[u])
    {
        isWhite[u] = false;
        --whiteNum;
    }
    else
    {
        isWhite[u] = true;
        ++whiteNum;
    }
    while (true)
    {
        int t = tree[idx[top[u]]];
        int oldVal = node[t].minL + 1;
        updateTree(t, idx[u]);
        int newVal = node[t].minL + 1;
        u = father[top[u]];
        if (-1 == u)
        {
            break;
        }
        multiset<int> &s = near[idx[u]];
        if (newVal != oldVal)
        {
            multiset<int>::iterator it = s.find(oldVal);
            if (it != s.end())
            {
                s.erase(it);
            }
            if (newVal < INF)
            {
                s.insert(newVal);
            }
        }
    }
}

void query(int u)
{
    if (0 == whiteNum)
    {
        puts("-1");
    }
    else if (isWhite[u])
    {
        puts("0");
    }
    else
    {
        int d = 0;
        int ans = INF;
        while (true)
        {
            int t = tree[idx[top[u]]];
            int l = node[t].l;
            int r = node[t].r;
            ans = min(ans, queryTreeR(t, l, idx[u]) + d);
            ans = min(ans, queryTreeL(t, idx[u], r) + d);
            d += idx[u] - l + 1;
            u = father[top[u]];
            if (-1 == u)
            {
                break;
            }
        }
        printf("%d\n", ans);
    }
}

int main()
{
    int u, v;
    while (~scanf("%d", &n))
    {
        init();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        initHeavy();
        buildTrees();
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            if (0 == u)
            {
                update(v);
            }
            else
            {
                query(v);
            }
        }
    }
    return 0;
}
