#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXM = MAXN * MAXN * 2;

struct TreeNode
{
    int l, r, w;
    int lazy;
} tree[MAXM * 3];

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].w = 0;
    tree[x].lazy = 0;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
}

void pushdown(int x)
{
    if (tree[x].lazy)
    {
        tree[x << 1].w += tree[x].lazy;
        tree[(x << 1) + 1].w += tree[x].lazy;
        tree[x << 1].lazy += tree[x].lazy;
        tree[(x << 1) + 1].lazy += tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void update(int x, int l, int r)
{
    if (l > r)
    {
        return;
    }
    if (tree[x].l == l && tree[x].r == r)
    {
        ++tree[x].w;
        ++tree[x].lazy;
        return;
    }
    pushdown(x);
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
}

int query(int x = 1)
{
    if (tree[x].l == tree[x].r)
    {
        return tree[x].w;
    }
    pushdown(x);
    return max(query(x << 1), query((x << 1) + 1));
}

int a[MAXN];
int set[MAXM], setNum;
map<int, int> indexs;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        setNum = 0;
        indexs.clear();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                set[setNum++] = a[i] + a[j];
                set[setNum++] = abs(a[i] - a[j]);
            }
        }
        sort(set, set + setNum);
        int k = 1;
        for (int i = 1; i < setNum; ++i)
        {
            if (set[i] != set[i - 1])
            {
                set[k++] = set[i];
            }
        }
        setNum = k;
        for (int i = 0; i < setNum; ++i)
        {
            indexs[set[i]] = i;
        }
        build(1, 0, setNum - 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int lower = indexs[abs(a[i] - a[j])];
                int upper = indexs[a[i] + a[j]] - 1;
                update(1, lower, upper);
            }
        }
        printf("%d\n", query());
    }
    return 0;
}
