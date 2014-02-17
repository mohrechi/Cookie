#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50000 + 10;

int n, a[MAXN];

struct TreeNode
{
    int l, r, sum;
    int maxL, maxR, opt;
} tree[MAXN * 3];

void pushUp(int x)
{
    int L = x << 1;
    int R = L + 1;
    tree[x].sum = (tree[L].sum + tree[R].sum);
    tree[x].maxL = max(tree[L].maxL, tree[L].sum + tree[R].maxL);
    tree[x].maxR = max(tree[R].maxR, tree[R].sum + tree[L].maxR);
    tree[x].opt = max(max(tree[L].opt, tree[R].opt), tree[L].maxR + tree[R].maxL);
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
    {
        tree[x].sum = a[l];
        tree[x].maxL = a[l];
        tree[x].maxR = a[l];
        tree[x].opt = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
    pushUp(x);
}

void update(int x, int pos, int val)
{
    if (tree[x].l == tree[x].r)
    {
        tree[x].sum = val;
        tree[x].maxL = val;
        tree[x].maxR = val;
        tree[x].opt = val;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        update(x << 1, pos, val);
    }
    else
    {
        update((x << 1) + 1, pos, val);
    }
    pushUp(x);
}

void query(int x, int l, int r, int &sum, int &maxL, int &maxR, int &opt)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        sum = tree[x].sum;
        maxL = tree[x].maxL;
        maxR = tree[x].maxR;
        opt = tree[x].opt;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        query(x << 1, l, r, sum, maxL, maxR, opt);
    }
    else if (l > mid)
    {
        query((x << 1) + 1, l, r, sum, maxL, maxR, opt);
    }
    else
    {
        int sumL, maxLL, maxRL, optL;
        int sumR, maxLR, maxRR, optR;
        query(x << 1, l, mid, sumL, maxLL, maxRL, optL);
        query((x << 1) + 1, mid + 1, r, sumR, maxLR, maxRR, optR);
        sum = sumL + sumR;
        maxL = max(maxLL, sumL + maxLR);
        maxR = max(maxRR, sumR + maxRL);
        opt = max(max(optL, optR), maxRL + maxLR);
    }
}

int query(int x, int l, int r)
{
    int sum, maxL, maxR, opt;
    query(x, l, r, sum, maxL, maxR, opt);
    return opt;
}

int main()
{
    int m, o, l, r;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d%d", &o, &l, &r);
            if (0 == o)
            {
                update(1, l, r);
            }
            else
            {
                printf("%d\n", query(1, l, r));
            }
        }
    }
    return 0;
}
