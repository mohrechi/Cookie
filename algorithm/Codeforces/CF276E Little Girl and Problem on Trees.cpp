#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

class SegmentTree
{
public:
    int len;
    SegmentTree(int len)
    {
        this->len = len;
        len = len * 4;
        for(int i=0;i<len;++i)
        {
            tree.push_back(TreeNode());
        }
        build(1, 1, this->len);
    }
    void build(int x, int l, int r)
    {
        tree[x].l = l;
        tree[x].r = r;
        tree[x].w = 0;
        if(l == r)
        {
            return;
        }
        int mid = (tree[x].l + tree[x].r) >> 1;
        build(lc(x), l, mid);
        build(rc(x), mid + 1, r);
    }
    void relax(int x)
    {
        if(tree[x].w)
        {
            tree[lc(x)].w += tree[x].w;
            tree[rc(x)].w += tree[x].w;
            tree[x].w = 0;
        }
    }
    void update(int x, int l, int r, int value)
    {
        if(tree[x].l == l && tree[x].r == r)
        {
            tree[x].w += value;
            return;
        }
        relax(x);
        int mid = (tree[x].l + tree[x].r) >> 1;
        if(r <= mid)
        {
            update(lc(x), l, r, value);
        }
        else if(l > mid)
        {
            update(rc(x), l, r, value);
        }
        else
        {
            update(lc(x), l, mid, value);
            update(rc(x), mid + 1, r, value);
        }
    }
    int query(int x, int pos)
    {
        if(tree[x].l == tree[x].r)
        {
            return tree[x].w;
        }
        relax(x);
        int mid = (tree[x].l + tree[x].r) >> 1;
        if(pos <= mid)
        {
            return query(lc(x), pos);
        }
        return query(rc(x), pos);
    }
private:
    struct TreeNode
    {
        int l, r, w;
    };
    vector<TreeNode> tree;
    inline int lc(const int x)
    {
        return x << 1;
    }
    inline int rc(const int x)
    {
        return (x << 1) + 1;
    }
};

struct Edge
{
    int v, next;
} edge[MAXN * 2];
int head[MAXN], edgeNumber;

void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int belong[MAXN];
int depth[MAXN];

int dfs(int x, int father, int deep, int color)
{
    belong[x] = color;
    depth[x] = deep;
    for(int i = head[x]; i != -1; i = edge[i].next)
    {
        if(edge[i].v != father)
        {
            return dfs(edge[i].v, x, deep + 1, color);
        }
    }
    return deep;
}

int main()
{
    int n, q, u, v;
    while(~scanf("%d%d", &n, &q))
    {
        clearEdge();
        for(int i = 1; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        vector<SegmentTree*> tree;
        int color = 0;
        int rootDepth = 1;
        for(int i = head[1]; i != -1; i = edge[i].next)
        {
            int deep = dfs(edge[i].v, 1, 1, color);
            tree.push_back(new SegmentTree(deep));
            rootDepth = max(rootDepth, deep);
            ++ color;
        }
        SegmentTree* rootTree = new SegmentTree(rootDepth);
        int root = 0;
        int op, v, x, d;
        while(q--)
        {
            scanf("%d", &op);
            if(0 == op)
            {
                scanf("%d%d%d", &v, &x, &d);
                if(v == 1)
                {
                    root += x;
                    rootTree->update(1, 1, min(d, rootTree->len), x);
                }
                else
                {
                    if(depth[v] > d)
                    {
                        tree[belong[v]]->update(1, depth[v] - d, min(depth[v] + d, tree[belong[v]]->len), x);
                    }
                    else if(depth[v] == d)
                    {
                        tree[belong[v]]->update(1, 1, min(depth[v] + d, tree[belong[v]]->len), x);
                        root += x;
                    }
                    else
                    {
                        if(d - depth[v] < tree[belong[v]]->len)
                        {
                            tree[belong[v]]->update(1, d - depth[v] + 1, min(depth[v] + d, tree[belong[v]]->len),x);
                        }
                        rootTree->update(1, 1, min(d - depth[v], rootTree->len), x);
                        root += x;
                    }
                }
            }
            else
            {
                scanf("%d", &v);
                if(1 == v)
                {
                    printf("%d\n", root);
                }
                else
                {
                    printf("%d\n", tree[belong[v]]->query(1, depth[v]) + rootTree->query(1, depth[v]));
                }
            }
        }
    }
    return 0;
}
