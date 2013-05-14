#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200005;

struct TreeNode
{
    int l, r, w, lazy;
} tree[MAXN * 3];

int n, q;
int a[MAXN], b[MAXN];

inline int lc(const int x)
{
    return x << 1;
}

inline int rc(const int x)
{
    return (x << 1) + 1;
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].w = 0;
    tree[x].lazy = 0;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void relax(int x)
{
    if(tree[x].lazy)
    {
        tree[lc(x)].w += tree[x].lazy;
        tree[rc(x)].w += tree[x].lazy;
        tree[lc(x)].lazy += tree[x].lazy;
        tree[rc(x)].lazy += tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void update(int x, int l, int r)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        ++ tree[x].w;
        ++ tree[x].lazy;
        return;
    }
    relax(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        update(lc(x), l, r);
    }
    else if(l > mid)
    {
        update(rc(x), l, r);
    }
    else
    {
        update(lc(x), l, mid);
        update(rc(x), mid + 1, r);
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

int main()
{
    int l, r;
    while(~scanf("%d%d", &n, &q))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        build(1, 1, n);
        for(int i=0;i<q;++i)
        {
            scanf("%d%d", &l, &r);
            update(1, l, r);
        }
        for(int i=0;i<n;++i)
        {
            b[i] = query(1, i + 1);
        }
        sort(b, b + n);
        long long ans = 0;
        for(int i=0;i<n;++i)
        {
            ans += (long long)a[i] * b[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
