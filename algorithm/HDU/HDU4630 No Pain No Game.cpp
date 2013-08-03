#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
const int MAXQ = 50005;
const int MAXF = 105;

struct SegmentTree
{
    int l, r;
    int maxGCD;
} tree[MAXN * 3];

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].maxGCD = 0;
    if (l != r)
    {
        int mid = (l + r) >> 1;
        build(x << 1, l, mid);
        build((x << 1) + 1, mid + 1, r);
    }
}

void pushdown(int x)
{
    if (tree[x].maxGCD)
    {
        tree[x << 1].maxGCD = max(tree[x << 1].maxGCD, tree[x].maxGCD);
        tree[(x << 1) + 1].maxGCD = max(tree[(x << 1) + 1].maxGCD, tree[x].maxGCD);
        tree[x].maxGCD = 0;
    }
}

void update(int x, int l, int r, int newGCD)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        tree[x].maxGCD = max(tree[x].maxGCD, newGCD);
        return;
    }
    pushdown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        update(x << 1, l, r, newGCD);
    }
    else if (l > mid)
    {
        update((x << 1) + 1, l, r, newGCD);
    }
    else
    {
        update(x << 1, l, mid, newGCD);
        update((x << 1) + 1, mid + 1, r, newGCD);
    }
}

int query(int x, int pos)
{
    if (tree[x].l == tree[x].r)
    {
        return tree[x].maxGCD;
    }
    pushdown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        return query(x << 1, pos);
    }
    return query((x << 1) + 1, pos);
}

int n, q;
int a[MAXN];
int ans[MAXQ];
struct Query
{
    int l, r;
    int index;
    friend bool operator <(const Query &a, const Query &b)
    {
        if (a.r == b.r)
        {
            return a.l < b.l;
        }
        return a.r < b.r;
    }
} queries[MAXQ];

int factorNum[MAXN];
int factor[MAXN][MAXF];

void init()
{
    int x = 0;
    for (int i = 1; i < MAXN; ++i)
    {
        for (int j = i; j < MAXN; j += i)
        {
            factor[j][factorNum[j]++] = i;
        }
    }
}

int prev[MAXN];

void insert(int index)
{
    for (int i = 0; i < factorNum[a[index]]; ++i)
    {
        int f = factor[a[index]][i];
        if (prev[f])
        {
            update(1, 1, prev[f], f);
        }
        prev[f] = index;
    }
}

int main()
{
    int T;
    init();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        scanf("%d", &q);
        for (int i = 0; i < q; ++i)
        {
            queries[i].index = i;
            scanf("%d%d", &queries[i].l, &queries[i].r);
        }
        sort(queries, queries + q);
        int right = 0;
        memset(prev, 0, sizeof(prev));
        build(1, 1, n);
        for (int i = 0; i < q; ++i)
        {
            while (right < queries[i].r)
            {
                insert(++right);
            }
            ans[queries[i].index] = query(1, queries[i].l);
        }
        for (int i = 0; i < q; ++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
