#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXQ = 2e5 + 10;

int n, p[MAXN], l[MAXN];
int q;
struct Query
{
    int x, y, index;
    bool operator <(const Query &query) const
    {
        if (x == query.x)
        {
            if (y == query.y)
            {
                return index > query.index;
            }
            return y > query.y;
        }
        return x > query.x;
    }
} queries[MAXQ];
int answers[MAXQ];

int locations[MAXN * 4];

struct TreeNode
{
    int l, r;
    int sum, lazy;
} tree[MAXN * 4 * 3];

inline int lchild(int x)
{
    return x << 1;
}

inline int rchild(int x)
{
    return lchild(x) + 1;
}

inline void pushUp(int x)
{
    tree[x].sum = tree[lchild(x)].sum + tree[rchild(x)].sum;
}

inline void pushDown(int x)
{
    if (tree[x].lazy)
    {
        tree[lchild(x)].sum = 0;
        tree[rchild(x)].sum = 0;
        tree[lchild(x)].lazy = 1;
        tree[rchild(x)].lazy = 1;
        tree[x].lazy = 0;
    }
}

void buildTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = 0;
    if (l == r)
    {
        tree[x].sum = locations[l + 1] - locations[l];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(lchild(x), l, mid);
    buildTree(rchild(x), mid + 1, r);
    pushUp(x);
}

void updateTree(int x, int l, int r)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        tree[x].sum = 0;
        tree[x].lazy = 1;
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        updateTree(lchild(x), l, r);
    }
    else if (l > mid)
    {
        updateTree(rchild(x), l, r);
    }
    else
    {
        updateTree(lchild(x), l, mid);
        updateTree(rchild(x), mid + 1, r);
    }
    pushUp(x);
}

int queryTree(int x, int l, int r)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        return tree[x].sum;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        return queryTree(lchild(x), l, r);
    }
    if (l > mid)
    {
        return queryTree(rchild(x), l, r);
    }
    return queryTree(lchild(x), l, mid) + queryTree(rchild(x), mid + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p[i], &l[i]);
    }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i)
    {
        queries[i].index = i;
        scanf("%d%d", &queries[i].x, &queries[i].y);
    }
    sort(queries + 1, queries + q + 1);
    set<int> locationSet;
    for (int i = 1; i <= n; ++i)
    {
        locationSet.insert(p[i]);
        locationSet.insert(p[i] - 1);
        locationSet.insert(p[i] + l[i]);
        locationSet.insert(p[i] + l[i] - 1);
    }
    int m = locationSet.size() - 1;
    int index = 0;
    map<int, int> indexes;
    for (auto it = locationSet.begin(); it != locationSet.end(); ++it)
    {
        indexes[*it] = ++index;
        locations[index] = *it;
    }
    int updated = n + 1;
    buildTree(1, 1, m);
    for (int i = 1; i <= q; ++i)
    {
        while (updated > queries[i].x)
        {
            --updated;
            updateTree(1, indexes[p[updated]], indexes[p[updated] + l[updated] - 1]);
        }
        answers[queries[i].index] = queryTree(1, indexes[p[queries[i].x]], indexes[p[queries[i].y] - 1]);
    }
    for (int i = 1; i <= q; ++i)
    {
        printf("%d\n", answers[i]);
    }
    return 0;
}
