#include <cstdio>
#include <cstring>
const int MAXN = 100005;

struct TreeNode
{
    int l, r, w;
}tree[MAXN * 3];
int a[MAXN];
int n, m;

inline int left(int x)
{
    return x << 1;
}

inline int right(int x)
{
    return (x << 1) + 1;
}

int build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if(l == r)
        return tree[x].w = a[l];
    int mid = (l + r) >> 1;
    return tree[x].w = build(left(x), l, mid) ^ build(right(x), mid + 1, r);
}

int update(int x, int pos, int value)
{
    if(tree[x].l == tree[x].r)
        return tree[x].w = value;
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(pos <= mid)
        return tree[x].w = update(left(x), pos, value) ^ tree[right(x)].w;
    return tree[x].w = tree[left(x)].w ^ update(right(x), pos, value);
}

int query(int x, int l, int r)
{
    if(tree[x].l == l && tree[x].r == r)
        return tree[x].w;
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
        return query(left(x), l, r);
    if(l > mid)
        return query(right(x), l, r);
    return query(left(x), l, mid) ^ query(right(x), mid + 1, r);
}

int main()
{
    int o, x, y;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;++i)
            scanf("%d", &a[i]);
        build(1, 1, n);
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &o, &x, &y);
            if(o == 1)
                update(1, x, y);
            else
                printf("%d\n", query(1, x, y));
        }
        printf("\n");
    }
    return 0;
}
