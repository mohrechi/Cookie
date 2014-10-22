#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n, m;
int a[MAXN], b[MAXN], pos[MAXN];
int ans[MAXN];
bool visit[MAXN];

struct SegmentTree
{
    int l, r, sum;
} tree[MAXN * 3];

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    if (l == r)
    {
        tree[x].sum = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
    tree[x].sum = tree[x << 1].sum + tree[(x << 1) + 1].sum;
}

void update(int x, int pos)
{
    ++tree[x].sum;
    if (tree[x].l == tree[x].r)
    {
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        update(x << 1, pos);
    }
    else
    {
        update((x << 1) + 1, pos);
    }
}

int query(int x, int l, int r)
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
    else if (l > mid)
    {
        return query((x << 1) + 1, l, r);
    }
    return query(x << 1, l, mid) + query((x << 1) + 1, mid + 1, r);
}

struct Query
{
    int l, r;
    int index;
    friend bool operator <(const Query &a, const Query &b)
    {
        if (a.l == b.l)
        {
            return a.r > b.r;
        }
        return a.l < b.l;
    }
} queries[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(visit, 0, sizeof(visit));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            int x = visit[a[i] - 1] + visit[a[i] + 1];
            if (x == 0)
            {
                b[i] = 1;
            }
            else if (x == 1)
            {
                b[i] = 0;
            }
            else
            {
                b[i] = -1;
            }
            visit[a[i]] = true;
            pos[a[i]] = i;
        }
        build(1, 1, n);
        for (int i = 0; i < m; ++i)
        {
            queries[i].index = i;
            scanf("%d%d", &queries[i].l, &queries[i].r);
        }
        sort(queries, queries + m);
        int left = 1;
        for (int i = 0; i < m; ++i)
        {
            while (left < queries[i].l)
            {
                if (a[left] - 1 >= 1)
                {
                    update(1, pos[a[left] - 1]);
                }
                if (a[left] + 1 <= n)
                {
                    update(1, pos[a[left] + 1]);
                }
                ++left;
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
