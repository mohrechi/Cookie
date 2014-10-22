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

int sum(int l, int r)
{
    int sum, maxL, maxR, opt;
    if (l > r)
    {
        return 0;
    }
    query(1, l, r, sum, maxL, maxR, opt);
    return sum;
}

int maxL(int l, int r)
{
    int sum, maxL, maxR, opt;
    if (l > r)
    {
        return 0;
    }
    query(1, l, r, sum, maxL, maxR, opt);
    return maxL;
}

int maxR(int l, int r)
{
    int sum, maxL, maxR, opt;
    if (l > r)
    {
        return 0;
    }
    query(1, l, r, sum, maxL, maxR, opt);
    return maxR;
}

int opt(int l, int r)
{
    int sum, maxL, maxR, opt;
    if (l > r)
    {
        return 0;
    }
    query(1, l, r, sum, maxL, maxR, opt);
    return opt;
}

int main()
{
    int T, m, x1, y1, x2, y2;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            int ans;
            if (y1 < x2)
            {
                ans = sum(y1 + 1, x2 - 1);
                ans += maxR(x1, y1);
                ans += maxL(x2, y2);
            }
            else
            {
                ans = opt(x2, y1);
                ans = max(ans, maxR(x1, x2) + maxL(x2, y2) - a[x2]);
                ans = max(ans, maxR(x1, y1) + maxL(y1, y2) - a[y1]);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
