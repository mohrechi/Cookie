#include <cstdio>
#include <cstring>
static const int MAXN = 100005;

int n, m;
int num[MAXN];
struct TreeNode
{
    int l, r;
    int max;
    int update;
}node[MAXN * 3];

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int lChild(int x)
{
    return x<<1;
}

inline int rChild(int x)
{
    return (x<<1) + 1;
}

void createTree(int x, int l, int r)
{
    node[x].l = l;
    node[x].r = r;
    node[x].update = 0;
    int mid = (l + r) >> 1;
    if(l == r)
    {
        node[x].max = num[l];
    }
    else
    {
        createTree(lChild(x), l, mid);
        createTree(rChild(x), mid+1, r);
        node[x].max = max(node[lChild(x)].max, node[rChild(x)].max);
    }
}

int searchTree(int x, int l, int r)
{
    int mid = (node[x].l + node[x].r) >> 1;
    if(node[x].l == l && node[x].r == r)
    {
        return node[x].max;
    }
    else
    {
        if(node[x].update)
        {
            node[lChild(x)].max += node[x].update;
            node[rChild(x)].max += node[x].update;
            node[lChild(x)].update += node[x].update;
            node[rChild(x)].update += node[x].update;
            node[x].update = 0;
        }
        if(r <= mid)
        {
            return searchTree(lChild(x), l, r);
        }
        else if(l > mid)
        {
            return searchTree(rChild(x), l, r);
        }
        else
        {
            return max(searchTree(lChild(x), l, mid), searchTree(rChild(x), mid+1, r));
        }
    }
}

void updateTree(int x, int l, int r, int v)
{
    int mid = (node[x].l + node[x].r) >> 1;
    if(node[x].l == l && node[x].r == r)
    {
        node[x].max += v;
        node[x].update += v;
    }
    else
    {
        if(node[x].update)
        {
            node[lChild(x)].max += node[x].update;
            node[rChild(x)].max += node[x].update;
            node[lChild(x)].update += node[x].update;
            node[rChild(x)].update += node[x].update;
            node[x].update = 0;
        }
        if(r <= mid)
        {
            updateTree(lChild(x), l, r, v);
        }
        else if(l > mid)
        {
            updateTree(rChild(x), l, r, v);
        }
        else
        {
            updateTree(lChild(x), l, mid, v);
            updateTree(rChild(x), mid+1, r, v);
        }
        node[x].max = max(node[lChild(x)].max, node[rChild(x)].max);
    }
}

int main()
{
    char op[5];
    int l, r, v;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&num[i]);
        }
        createTree(1, 1, n);
        while(m--)
        {
            scanf("%s", op);
            if(*op == 'Q')
            {
                scanf("%d%d", &l,&r);
                printf("%d\n", searchTree(1, l, r));
            }
            else
            {
                scanf("%d%d%d", &l,&r,&v);
                updateTree(1, l, r, v);
            }
        }
    }
    return 0;
}
