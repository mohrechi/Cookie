#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 100005;

struct Set
{
    int data[MAXN * 3];
    int dataNumber;
    map<int, int> rdata;

    inline void clear()
    {
        dataNumber = 0;
    }

    inline void push(int x)
    {
        data[dataNumber++] = x;
    }

    inline void simplify()
    {
        sort(data, data + dataNumber);
        int k = 1;
        for(int i=1;i<dataNumber;++i)
        {
            if(data[i] != data[i-1])
            {
                data[k++] = data[i];
            }
        }
        dataNumber = k;
        rdata.clear();
        for(int i=0;i<dataNumber;++i)
        {
            rdata[data[i]] = i;
        }
    }
}set;

int n, m;
int s[MAXN], t[MAXN], q[MAXN];

struct Tree
{
    int l, r, sum, lazy;
}tree[MAXN * 12];

void buildTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].sum = 0;
    tree[x].lazy = 0;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    x <<= 1;
    buildTree(x, l, mid);
    buildTree(x+1, mid+1, r);
}

void relaxTree(int x)
{
    if(tree[x].lazy)
    {
        tree[x<<1].sum += tree[x].lazy;
        tree[x<<1].lazy += tree[x].lazy;
        tree[(x<<1)+1].sum += tree[x].lazy;
        tree[(x<<1)+1].lazy += tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void updateTree(int x, int l, int r)
{
    if(tree[x].l == l && tree[x].r == r)
    {
        ++ tree[x].sum;
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
        updateTree(x+1, l, r);
    }
    else
    {
        updateTree(x, l, mid);
        updateTree(x+1, mid+1, r);
    }
}

int queryTree(int x, int pos)
{
    if(tree[x].l == tree[x].r)
    {
        return tree[x].sum;
    }
    relaxTree(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    x <<= 1;
    if(pos <= mid)
    {
        return queryTree(x, pos);
    }
    else
    {
        return queryTree(x+1, pos);
    }
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int k=1;k<=caseNumber;++k)
    {
        scanf("%d%d",&n,&m);
        set.clear();
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&s[i],&t[i]);
            set.push(s[i]);
            set.push(t[i]);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d", &q[i]);
            set.push(q[i]);
        }
        set.simplify();
        buildTree(1, 1, set.dataNumber);
        for(int i=0;i<n;++i)
        {
            updateTree(1, set.rdata[s[i]] + 1, set.rdata[t[i]] + 1);
        }
        printf("Case #%d:\n", k);
        for(int i=0;i<m;++i)
        {
            printf("%d\n", queryTree(1, set.rdata[q[i]] + 1));
        }
    }
    return 0;
}
