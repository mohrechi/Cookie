#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXM = 100000 + 10;
const int MAXQ = 100000 + 10;

struct TreeNode
{
    int l, r;
    int val, lazy;
    int maxVal, maxLazy;
} tree[MAXN * 3];

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].val = 0;
    tree[x].lazy = 0;
    tree[x].maxVal = 0;
    tree[x].maxLazy = 0;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
}

inline void pushUp(const int &x)
{
    int L = x << 1;
    int R = L + 1;
    tree[x].val = max(tree[L].val, tree[R].val);
    tree[x].maxVal = max(tree[L].maxVal, tree[R].maxVal);
}

inline void pushDown(int x)
{
    if (tree[x].lazy)
    {
        int lazy = tree[x].lazy;
        int maxLazy = tree[x].maxLazy;
        int L = x << 1;
        int R = L + 1;
        int sizeL = tree[L].r - tree[L].l + 1;
        int sizeR = tree[R].r - tree[R].l + 1;
        tree[L].maxLazy = max(tree[L].maxLazy, tree[L].lazy + maxLazy);
        tree[R].maxLazy = max(tree[R].maxLazy, tree[R].lazy + maxLazy);
        tree[L].maxVal = max(tree[L].maxVal, tree[L].val + maxLazy);
        tree[R].maxVal = max(tree[R].maxVal, tree[R].val + maxLazy);
        tree[L].val += lazy;
        tree[R].val += lazy;
        tree[L].lazy += lazy;
        tree[R].lazy += lazy;
        tree[x].lazy = 0;
        tree[x].maxLazy = 0;
    }
}

void update(int x, int l, int r, int val)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        tree[x].val += val;
        tree[x].lazy += val;
        tree[x].maxVal = max(tree[x].maxVal, tree[x].val);
        tree[x].maxLazy = max(tree[x].maxLazy, tree[x].lazy);
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        update(x << 1, l, r, val);
    }
    else if (l > mid)
    {
        update((x << 1) + 1, l, r, val);
    }
    else
    {
        update(x << 1, l, mid, val);
        update((x << 1) + 1, mid + 1, r, val);
    }
    pushUp(x);
}

int query(int x, int l, int r)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        return tree[x].maxVal;
    }
    pushDown(x);
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

int last[MAXM * 2];

void clearLast()
{
    memset(last, 0, sizeof(last));
}

inline void setLast(const int &x, const int &pos)
{
    last[MAXM + x] = pos;
}

inline int getLast(const int &x)
{
    return last[MAXM + x];
}

int n, score[MAXN];
struct Query
{
    int l, r, index;
    bool operator <(const Query &query) const
    {
        return r < query.r;
    }
} queries[MAXQ];
int ans[MAXQ];

int main()
{
    int m, l, r;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &score[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        for (int i = 0; i < m; ++i)
        {
            queries[i].index = i;
            scanf("%d%d", &queries[i].l, &queries[i].r);
        }
        sort(queries, queries + m);
        int r = 0;
        clearLast();
        for (int i = 0; i < m; ++i)
        {
            while (r < queries[i].r)
            {
                ++r;
                int pos = getLast(score[r]) + 1;
                setLast(score[r], r);
                update(1, pos, r, score[r]);
            }
            ans[queries[i].index] = query(1, queries[i].l, queries[i].r);
        }
        for (int i = 0; i < m; ++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
