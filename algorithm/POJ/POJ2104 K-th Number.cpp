//#define METHOD_NORMAL
#define METHOD_PARTITION_TREE

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
