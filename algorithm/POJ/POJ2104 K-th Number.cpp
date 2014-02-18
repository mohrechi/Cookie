//#define METHOD_NORMAL
//#define METHOD_PARTITION_TREE
#define METHOD_PERSISTENT_SEGMENT_TREE

#if defined(METHOD_NORMAL)
#include<iostream>
#include<algorithm>
using namespace std;
struct In
{
    int x;
    int id;
}s[100015];
int cmp( const void *a , const void *b )
{
    struct In *c = (In *)a;
    struct In *d = (In *)b;
    return c->x-d->x;
}

int main()
{
    int m,n;
    int a,b,c,i;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i].x);
        s[i].id=i;
    }
    qsort(s,n,sizeof(s[0]),cmp);
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        for(i=0;i<n;i++)
        {
            if(s[i].id>=a-1 && s[i].id<=b-1)
                c--;
            if(c==0)
                break;
        }
        printf("%d\n",s[i].x);
    }
    return 0;
}
#elif defined(METHOD_PARTITION_TREE)
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
static const int MAXN = 100005;
static const int MAXM = 5005;

struct TreeNode
{
    int l, r;
}node[MAXN<<2];

int leftNumber[20][MAXN];
int treeValue[20][MAXN];
int sortedArray[MAXN];

void buildTree(int l, int r, int c, int d)
{
    node[c].l = l;
    node[c].r = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    int sameNumber = mid - l + 1;
    for(int i=l;i<=r;++i)
        if(treeValue[d][i] < sortedArray[mid])
            --sameNumber;
    int pLeft = l, pRight = mid + 1;
    for(int i=l;i<=r;++i)
    {
        leftNumber[d][i] = (i==l?0:leftNumber[d][i-1]);
        if(treeValue[d][i] < sortedArray[mid])
        {
            treeValue[d+1][pLeft++] = treeValue[d][i];
            ++leftNumber[d][i];
        }
        else if(treeValue[d][i] > sortedArray[mid])
        {
            treeValue[d+1][pRight++] = treeValue[d][i];
        }
        else if(sameNumber)
        {
            treeValue[d+1][pLeft++] = treeValue[d][i];
            ++leftNumber[d][i];
            --sameNumber;
        }
        else
        {
            treeValue[d+1][pRight++] = treeValue[d][i];
        }
    }
    buildTree(l, mid, (c<<1)+1, d + 1);
    buildTree(mid+1, r, (c<<1)+2, d + 1);
}

int query(int l, int r, int c, int d, int k)
{
    if(l == r) return treeValue[d][l];
    int lLeft = (l==node[c].l?0:leftNumber[d][l-1]);
    int rLeft = leftNumber[d][r];
    int totalLeft = rLeft - lLeft;
    if(k <= totalLeft)
    {
        return query(node[c].l + lLeft, node[c].l + rLeft - 1, (c<<1)+1, d+1, k);
    }
    int mid = (node[c].l + node[c].r) >> 1;
    int lRight = l - node[c].l - lLeft;
    int totalRight = r - l + 1 - totalLeft;
    return query(mid + lRight + 1, mid + lRight + totalRight, (c<<1)+2, d + 1, k - totalLeft);
}

int main(int argc, char *argv[])
{
    int n,m,l,r,k;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",&sortedArray[i]);
            treeValue[0][i] = sortedArray[i];
        }
        sort(sortedArray, sortedArray + n);
        buildTree(0, n-1, 0, 0);
        while(m--)
        {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",query(l-1, r-1, 0, 0, k));
        }
    }
    return 0;
}
#endif

#ifdef METHOD_PERSISTENT_SEGMENT_TREE
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

struct TreeNode
{
    int l, r;
    int lc, rc;
    int sum;
} tree[MAXN * 20];
int treeNum, root[MAXN];

int build(int l, int r)
{
    int x = treeNum++;
    tree[x].l = l;
    tree[x].r = r;
    tree[x].sum = 0;
    if (l == r)
    {
        return x;
    }
    int mid = (l + r) >> 1;
    tree[x].lc = build(l, mid);
    tree[x].rc = build(mid + 1, r);
    return x;
}

int update(int o, int pos, int val)
{
    int x = treeNum++;
    tree[x] = tree[o];
    tree[x].sum += val;
    if (tree[o].l == tree[o].r)
    {
        return x;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        tree[x].lc = update(tree[o].lc, pos, val);
    }
    else
    {
        tree[x].rc = update(tree[o].rc, pos, val);
    }
    return x;
}

int query(int x, int o, int k)
{
    if (tree[x].l == tree[x].r)
    {
        return tree[x].l;
    }
    int num = tree[tree[x].lc].sum - tree[tree[o].lc].sum;
    if (k <= num)
    {
        return query(tree[x].lc, tree[o].lc, k);
    }
    return query(tree[x].rc, tree[o].rc, k - num);
}

int n, m, c;
int a[MAXN];
struct Node
{
    int val, index;
    bool operator <(const Node &node) const
    {
        return val < node.val;
    }
} node[MAXN];
int pos[MAXN];

int main()
{
    int l, r, k;
    while (~scanf("%d%d", &n, &m))
    {
        treeNum = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            node[i].val = a[i];
            node[i].index = i;
        }
        sort(node + 1, node + 1 + n);
        pos[node[1].index] = 1;
        int j = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (node[i].val == node[i - 1].val)
            {
                pos[node[i].index] = j;
            }
            else
            {
                pos[node[i].index] = ++j;
                node[j] = node[i];
            }
        }
        root[0] = build(1, j);
        for (int i = 1; i <= n; ++i)
        {
            root[i] = update(root[i - 1], pos[i], 1);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &l, &r, &k);
            printf("%d\n", node[query(root[r], root[l - 1], k)].val);
        }
    }
    return 0;
}
#endif // METHOD_PERSISTENT_SEGMENT_TREE
