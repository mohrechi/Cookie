#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int n, m;
long long val[MAXN];

struct TreeNode
{
    int l, r;
    long long sum;
} tree[MAXN * 3];

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
    {
        tree[x].sum = val[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
    tree[x].sum = tree[x << 1].sum + tree[(x << 1) + 1].sum;
}

void update(int x, int l, int r)
{
    if (tree[x].r - tree[x].l + 1 == tree[x].sum)
    {
        return;
    }
    if (tree[x].l == tree[x].r)
    {
        tree[x].sum = (long long)sqrt((double)tree[x].sum);
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        update(x << 1, l, r);
    }
    else if (l > mid)
    {
        update((x << 1) + 1, l, r);
    }
    else
    {
        update(x << 1, l, mid);
        update((x << 1) + 1, mid + 1, r);
    }
    tree[x].sum = tree[x << 1].sum + tree[(x << 1) + 1].sum;
}

long long query(int x, int l, int r)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        return tree[x].sum;
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
    return query(x << 1, l, mid) + query((x << 1) + 1, mid + 1, r);
}

int main()
{
    int T = 0, o, a, b;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &val[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        printf("Case #%d:\n", ++T);
        while (m--)
        {
            scanf("%d%d%d", &o, &a, &b);
            if (a > b)
            {
                swap(a, b);
            }
            if (0 == o)
            {
                update(1, a, b);
            }
            else
            {
                printf("%lld\n", query(1, a, b));
            }
        }
        putchar('\n');
    }
    return 0;
}
