#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 10000005;

int bl[MAXN], br[MAXN];
int hash[MAXM];

struct Stack
{
    int a[MAXN * 2];
    int top;
    void clear()
    {
        top = 0;
    }
    void insert(int x)
    {
        a[top ++] = x;
    }
    void ssort()
    {
        sort(a, a + top);
    }
}in1, in2;

struct TreeNode
{
    int l, r;
    int value, lazy;
}tree[MAXN * 8];

inline int left(int x)
{
    return x << 1;
}

inline int right(int x)
{
    return (x << 1) + 1;
}

void initTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = 0;
    tree[x].value = 0;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    initTree(left(x), l, mid);
    initTree(right(x), mid + 1, r);
}

void relaxTree(int x)
{
    if(tree[x].lazy)
    {
        tree[left(x)].value = tree[x].lazy;
        tree[left(x)].lazy = tree[x].lazy;
        tree[right(x)].value = tree[x].lazy;
        tree[right(x)].lazy = tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void updateTree(int x, int l, int r, int value)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        tree[x].value = value;
        tree[x].lazy = value;
        return;
    }
    relaxTree(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        updateTree(left(x), l, r, value);
    }
    else if(l > mid)
    {
        updateTree(right(x), l, r, value);
    }
    else
    {
        updateTree(left(x), l, mid, value);
        updateTree(right(x), mid + 1, r, value);
    }
}

void queryTree(int x)
{
    if(tree[x].l == tree[x].r)
    {
        in1.insert(tree[x].value);
        return;
    }
    if(tree[x].lazy)
    {
        in1.insert(tree[x].value);
        return;
    }
    queryTree(left(x));
    queryTree(right(x));
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        in1.clear();
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &bl[i], &br[i]);
            in1.insert(bl[i]);
            in1.insert(br[i]);
        }
        in1.ssort();
        in2.clear();
        in2.insert(in1.a[0]);
        for(int i=1;i<in1.top;++i)
        {
            if(in1.a[i] == in1.a[i-1])
            {
                continue;
            }
            in2.insert(in1.a[i]);
        }
        int num = 0;
        for(int i=0;i<in2.top;++i)
        {
            hash[in2.a[i]] = ++ num;
        }
        initTree(1, 1, num);
        for(int i=0;i<n;++i)
        {
            updateTree(1, hash[bl[i]], hash[br[i]], i);
        }
        in1.clear();
        queryTree(1);
        in1.ssort();
        in2.clear();
        in2.insert(in1.a[0]);
        for(int i=1;i<in1.top;++i)
        {
            if(in1.a[i] == in1.a[i-1])
            {
                continue;
            }
            in2.insert(in1.a[i]);
        }
        int ans = in2.top;
        if(in2.a[0] == -1)
        {
            -- ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
