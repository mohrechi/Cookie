#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAXN = 100005;

struct TreeNode
{
    int l, r;
    int w, lazy;
}tree[MAXN * 3];

void buildTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].w = 0;
    tree[x].lazy = 0;
    if(l < r)
    {
        int mid = (l + r) >> 1;
        x <<= 1;
        buildTree(x, l, mid);
        buildTree(x + 1, mid + 1, r);
    }
}

void relaxTree(int x)
{
    if(tree[x].lazy)
    {
        int t = x << 1;
        tree[t].w += tree[x].lazy;
        tree[t].lazy += tree[x].lazy;
        tree[t+1].w += tree[x].lazy;
        tree[t+1].lazy += tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void updateTree(int x, int l, int r)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        ++ tree[x].w;
        ++ tree[x].lazy;
        return;
    }
    relaxTree(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    x <<= 1;
    if(r <= mid)
    {
        updateTree(x, l, r);
    }
    else if(l > mid)
    {
        updateTree(x + 1, l, r);
    }
    else
    {
        updateTree(x, l, mid);
        updateTree(x + 1, mid + 1, r);
    }
}

int query(int x, int pos)
{
    if(tree[x].l == tree[x].r)
    {
        return tree[x].w;
    }
    relaxTree(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    x <<= 1;
    if(pos <= mid)
    {
        return query(x, pos);
    }
    else
    {
        return query(x + 1, pos);
    }
}

int n;
struct Node
{
    int l, r;
    int index;
}node[MAXN];
int ans[MAXN];

bool operator < (const Node &a, const Node &b)
{
    if(a.r == b.r)
    {
        return a.l < b.l;
    }
    return a.r > b.r;
}

inline int max(int x, int y)
{
    return x > y ? x : y;
}

int main()
{
    while(scanf("%d", &n), n)
    {
        int maxValue = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &node[i].l, &node[i].r);
            node[i].index = i;
            maxValue = max(maxValue, node[i].r);
        }
        sort(node, node + n);
        buildTree(1, 0, maxValue);
        for(int i=0;i<n;++i)
        {
            updateTree(1, node[i].l, maxValue);
            if(i)
            {
                if(node[i].l == node[i-1].l && node[i].r == node[i-1].r)
                {
                    ans[node[i].index] = ans[node[i - 1].index];
                    continue;
                }
            }
            ans[node[i].index] = query(1, node[i].l) - 1;
        }
        printf("%d", ans[0]);
        for(int i=1;i<n;++i)
        {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
