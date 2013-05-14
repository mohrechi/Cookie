#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
const int MAXK = 11;
const int MAXM = MAXK * (MAXK - 1) / 2;

int getStatus(int k, int mod)
{
    int status = 0;
    for (int i = 1; i < k; ++i)
    {
        status += i;
    }
    return status + mod;
}

struct TreeNode
{
    int l, r, w[MAXM];
} tree[MAXN * 3];
int N, A[MAXN];

inline int lc(const int &x)
{
    return x << 1;
}

inline int rc(const int &x)
{
    return lc(x) + 1;
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    memset(tree[x].w, 0, sizeof(tree[x].w));
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void relax(int x, int status)
{
    if (tree[x].w[status])
    {
        tree[lc(x)].w[status] += tree[x].w[status];
        tree[rc(x)].w[status] += tree[x].w[status];
        tree[x].w[status] = 0;
    }
}

void relax(int x)
{
    for (int i = 0; i < MAXM; ++i)
    {
        relax(x, i);
    }
}

void update(int x, int l, int r, int w, int status)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        tree[x].w[status] += w;
        return;
    }
    relax(x, status);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        update(lc(x), l, r, w, status);
    }
    else if (l > mid)
    {
        update(rc(x), l, r, w, status);
    }
    else
    {
        update(lc(x), l, mid, w, status);
        update(rc(x), mid + 1, r, w, status);
    }
}

int query(int x, int pos)
{
    if (tree[x].l == pos && tree[x].r == pos)
    {
        int res = A[pos];
        for (int i = 1; i < MAXK; ++i)
        {
            res += tree[x].w[getStatus(i, (pos - 1) % i)];
        }
        return res;
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        return query(lc(x), pos);
    }
    else
    {
        return query(rc(x), pos);
    }
}

int main()
{
    int Q, o, a, b, k, c;
    while (~scanf("%d", &N))
    {
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &A[i]);
        }
        build(1, 1, N);
        scanf("%d", &Q);
        while (Q--)
        {
            scanf("%d", &o);
            if (o == 1)
            {
                scanf("%d%d%d%d", &a, &b, &k, &c);
                update(1, a, b, c, getStatus(k, (a - 1) % k));
            }
            else
            {
                scanf("%d", &a);
                printf("%d\n", query(1, a));
            }
        }
    }
    return 0;
}
