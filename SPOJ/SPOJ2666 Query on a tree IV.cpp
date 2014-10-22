#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int INF = 0x3f3f3f3f;

int n;
multiset< int, greater<int> > deep[MAXN], global;

int stamp;
int size[MAXN], depth[MAXN];
int father[MAXN], son[MAXN], weight[MAXN];
int top[MAXN], idx[MAXN], pos[MAXN];
bool isWhite[MAXN];
int whiteNum;

inline int getD1(int u)
{
    if (deep[u].size() > 0)
    {
        return *deep[u].begin();
    }
    return -INF;
}

inline int getD2(int u)
{
    if (deep[u].size() > 1)
    {
        int x = *deep[u].begin();
        deep[u].erase(deep[u].begin());
        int y = *deep[u].begin();
        deep[u].insert(x);
        return y;
    }
    return -INF;
}

struct Edge
{
    int v, w, next;
} edge[MAXN * 2];
int edgeNum, head[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(const int &u, const int &v, const int &w)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(const int &u, const int &v, const int &w)
{
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

int dist[MAXN];

inline int getDist(int u, int v)
{
    return dist[v] - dist[u];
}

struct TreeNode
{
    int l, r, lc, rc;
    int maxL, maxR, opt;
} node[MAXN * 3];
int nodeNum, tree[MAXN];

void initNode(int x)
{
    int d1 = getD1(node[x].l);
    int d2 = getD2(node[x].l);
    node[x].maxL = d1;
    node[x].maxR = d1;
    node[x].opt = d1 + d2;
    if (isWhite[pos[node[x].l]])
    {
        node[x].opt = max(node[x].opt, d1);
    }
}

void pushUp(int x)
{
    int L = node[x].lc;
    int R = node[x].rc;
    int mid = (node[x].l + node[x].r) >> 1;
    node[x].maxL = max(node[L].maxL, node[R].maxL + getDist(node[x].l, mid + 1));
    node[x].maxR = max(node[R].maxR, node[L].maxR + getDist(mid, node[x].r));
    node[x].opt = max(node[L].opt, node[R].opt);
    node[x].opt = max(node[x].opt, node[L].maxR + node[R].maxL + getDist(mid, mid + 1));
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
            weight[v] = edge[i].w;
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
    nodeNum = 0;
    initRelation(1);
    initIndex(1);
    for (int i = 1; i <= n; ++i)
    {
        deep[i].clear();
    }
}

void initDist(int l, int r)
{
    for (int i = l + 1; i <= r; ++i)
    {
        dist[i] += dist[i - 1];
    }
}

void buildTrees(int u, int f, int w)
{
    if (isWhite[u])
    {
        deep[idx[u]].insert(0);
    }
    if (u == top[u])
    {
        dist[idx[u]] = 0;
    }
    else
    {
        dist[idx[u]] = w;
    }
    int e;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].v;
        int w = edge[i].w;
        if (v == son[u])
        {
            e = i;
            continue;
        }
        if (v != f)
        {
            buildTrees(v, u, w);
            deep[idx[u]].insert(node[tree[idx[v]]].maxL + w);
        }
    }
    if (son[u])
    {
        buildTrees(son[u], u, edge[e].w);
    }
    else
    {
        initDist(idx[top[u]], idx[u]);
        tree[idx[top[u]]] = buildTree(idx[top[u]], idx[u]);
        global.insert(node[tree[idx[top[u]]]].opt);
    }
}

void buildTrees()
{
    buildTrees(1, -1, 0);
}

void init()
{
    nodeNum = 0;
    clearEdge();
    whiteNum = n;
    memset(isWhite, true, sizeof(isWhite));
    for (int i = 0; i <= n; ++i)
    {
        deep[i].clear();
    }
    global.clear();
}

void update(int u)
{
    if (isWhite[u])
    {
        isWhite[u] = false;
        --whiteNum;
        deep[idx[u]].erase(deep[idx[u]].find(0));
    }
    else
    {
        isWhite[u] = true;
        ++whiteNum;
        deep[idx[u]].insert(0);
    }
    while (true)
    {
        int w = weight[top[u]];
        int t = tree[idx[top[u]]];
        int oldVal = w + node[t].maxL;
        global.erase(global.find(node[t].opt));
        updateTree(t, idx[u]);
        global.insert(node[t].opt);
        int newVal = w + node[t].maxL;
        u = father[top[u]];
        if (u == -1)
        {
            break;
        }
        else
        {
            multiset< int, greater<int> > &s = deep[idx[u]];
            if (newVal != oldVal)
            {
                s.erase(s.find(oldVal));
                s.insert(newVal);
            }
        }
    }
}

void query()
{
    if (0 == whiteNum)
    {
        puts("They have disappeared.");
    }
    else
    {
        printf("%d\n", *global.begin());
    }
}

int main()
{
    int m, u, v, w;
    char op[4];
    while (~scanf("%d", &n))
    {
        init();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        initHeavy();
        buildTrees();
        scanf("%d", &m);
        while (m--)
        {
            scanf("%s", op);
            if ('A' == *op)
            {
                query();
            }
            else
            {
                scanf("%d", &u);
                update(u);
            }
        }
    }
    return 0;
}
