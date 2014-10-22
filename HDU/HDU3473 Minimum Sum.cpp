#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
static const int MAXN = 100005;

struct TreeNode
{
    int l, r;
}node[MAXN<<2];

int leftNumber[20][MAXN];
int treeValue[20][MAXN];
int sortedArray[MAXN];
__int64 sum[20][MAXN];
__int64 totalSum;
__int64 originSum[MAXN];

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
        sum[d][i] = (i==l?0:sum[d][i-1]);
        if(treeValue[d][i] < sortedArray[mid])
        {
            treeValue[d+1][pLeft++] = treeValue[d][i];
            sum[d][i] += treeValue[d][i];
            ++leftNumber[d][i];
        }
        else if(treeValue[d][i] > sortedArray[mid])
        {
            treeValue[d+1][pRight++] = treeValue[d][i];
        }
        else if(sameNumber)
        {
            treeValue[d+1][pLeft++] = treeValue[d][i];
            sum[d][i] += treeValue[d][i];
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
    __int64 tSum = (l==node[c].l?sum[d][r]:sum[d][r]-sum[d][l-1]);
    if(k <= totalLeft)
    {
        return query(node[c].l + lLeft, node[c].l + rLeft - 1, (c<<1)+1, d+1, k);
    }
    totalSum += tSum;
    int mid = (node[c].l + node[c].r) >> 1;
    int lRight = l - node[c].l - lLeft;
    int totalRight = r - l + 1 - totalLeft;
    return query(mid + lRight + 1, mid + lRight + totalRight, (c<<1)+2, d + 1, k - totalLeft);
}

int main(int argc, char *argv[])
{
    int t,n,m,l,r;
    scanf("%d",&t);
    for(int k=1;k<=t;++k)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&sortedArray[i]);
            treeValue[0][i] = sortedArray[i];
            originSum[i] = sortedArray[i];
        }
        for(int i=1;i<n;++i)
        {
            originSum[i] += originSum[i-1];
        }
        sort(sortedArray, sortedArray + n);
        buildTree(0, n-1, 0, 0);
        printf("Case #%d:\n", k);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&l,&r);
            totalSum = 0;
            int mid = query(l, r, 0, 0, (r-l+2)>>1);
            printf("%I64d\n", originSum[r]-originSum[l-1]-totalSum * 2 - mid * (((r-l)&1)?2:1));
        }
        printf("\n");
    }
    return 0;
}
