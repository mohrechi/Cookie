#include <cstdio>
#include <cstring>
static const int MAXN = 100001;

int n, m;
struct TreeNode
{
    int l, r;
    long long sum, update;
}node[MAXN * 3];
long long num[MAXN];

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int left(int x)
{
    return x << 1;
}

inline int right(int x)
{
    return (x << 1) + 1;
}

inline int midium(int x, int y)
{
    return (x + y) >> 1;
}

inline int nodeLength(int x)
{
    return node[x].r - node[x].l + 1;
}

void createTree(int x, int l, int r)
{
    node[x].l = l;
    node[x].r = r;
    node[x].update = 0;
    if(l == r)
    {
        node[x].sum = num[l];
    }
    else
    {
        int mid = midium(l, r);
        createTree(left(x), l, mid);
        createTree(right(x), mid + 1, r);
        node[x].sum = node[left(x)].sum + node[right(x)].sum;
    }
}

void updateTreeNode(int x)
{
    if(node[x].update)
    {
        node[left(x)].sum += node[x].update * nodeLength(left(x));
        node[left(x)].update += node[x].update;
        node[right(x)].sum += node[x].update * nodeLength(right(x));
        node[right(x)].update += node[x].update;
        node[x].update = 0;
    }
}

void updateTree(int x, int l, int r, int v)
{
    if(node[x].l == l && node[x].r == r)
    {
        node[x].sum += v * nodeLength(x);
        node[x].update += v;
    }
    else
    {
        updateTreeNode(x);
        int mid = midium(node[x].l, node[x].r);
        if(r <= mid)
        {
            updateTree(left(x), l, r, v);
        }
        else if(l > mid)
        {
            updateTree(right(x), l, r, v);
        }
        else
        {
            updateTree(left(x), l, mid, v);
            updateTree(right(x), mid + 1, r, v);
        }
        node[x].sum = node[left(x)].sum + node[right(x)].sum;
    }
}

long long searchTree(int x, int l, int r)
{
    if(node[x].l == l && node[x].r == r)
    {
        return node[x].sum;
    }
    updateTreeNode(x);
    int mid = midium(node[x].l, node[x].r);
    if(r <= mid)
    {
        return searchTree(left(x), l, r);
    }
    else if(l > mid)
    {
        return searchTree(right(x), l, r);
    }
    else
    {
        return searchTree(left(x), l, mid) + searchTree(right(x), mid+1, r);
    }
}

int main()
{
    char op[5];
    int a, b, c;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%lld", &num[i]);
        }
        createTree(1, 1, n);
        while(m--)
        {
            scanf("%s", &op);
            switch(*op)
            {
            case 'Q':
                scanf("%d%d",&a,&b);
                printf("%lld\n", searchTree(1, a, b));
                break;
            case 'C':
                scanf("%d%d%d",&a,&b,&c);
                updateTree(1, a, b, c);
                break;
            }
        }
    }
    return 0;
}
