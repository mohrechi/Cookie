#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000010;

struct TreeNode
{
    int l, r;
    int lSame, rSame;
    int lLazy, rLazy;
}tree[MAXN * 3];

char s1[MAXN], s2[MAXN];
int l1, l2;
int lSame[MAXN], rSame[MAXN];

void buildTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lSame = lSame[l-1] + 1;
    tree[x].rSame = rSame[r-1] + 1;
    tree[x].lLazy = -1;
    tree[x].rLazy = -1;
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
    int xx = x << 1;
    if(tree[x].lLazy != -1)
    {
        tree[xx].lLazy = tree[x].lLazy;
        tree[xx].lSame = tree[x].lSame;
        tree[xx+1].lLazy = tree[x].lLazy;
        tree[xx+1].lSame = tree[x].lSame;
        tree[x].lLazy = -1;
    }
    if(tree[x].rLazy != -1)
    {
        tree[xx].rLazy = tree[x].rLazy;
        tree[xx].rSame = tree[x].rSame;
        tree[xx+1].rLazy = tree[x].rLazy;
        tree[xx+1].rSame = tree[x].rSame;
        tree[x].rLazy = -1;
    }
}

void updateTree(int x, int l, int r, int ld, int rd)
{
    if(l > r)
    {
        return;
    }
    if(tree[x].l == l && tree[x].r == r)
    {
        if(ld != -1)
        {
            tree[x].lSame = ld;
            tree[x].lLazy = ld;
        }
        if(rd != -1)
        {
            tree[x].rSame = rd;
            tree[x].rLazy = rd;
        }
        return;
    }
    relaxTree(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    x <<= 1;
    if(r <= mid)
    {
        updateTree(x, l, r, ld, rd);
    }
    else if(l > mid)
    {
        updateTree(x+1, l, r, ld, rd);
    }
    else
    {
        updateTree(x, l, mid, ld, rd);
        updateTree(x+1, mid+1, r, ld, rd);
    }
}

TreeNode queryTree(int x, int pos)
{
    if(tree[x].l == tree[x].r)
    {
        return tree[x];
    }
    relaxTree(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    x <<= 1;
    if(pos <= mid)
    {
        return queryTree(x, pos);
    }
    return queryTree(x+1, pos);
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        int q;
        scanf("%s%s",s1,s2);
        l1 = strlen(s1);
        l2 = strlen(s2);
        int lmax = max(l1, l2);
        for(int i=l1;i<=lmax;++i)
        {
            s1[i] = 0;
        }
        for(int i=l2;i<=lmax;++i)
        {
            s2[i] = 0;
        }
        int minSame = 0;
        for(int i=0;i<lmax;++i)
        {
            lSame[i] = minSame;
            if(s1[i] != s2[i])
            {
                minSame = i + 1;
            }
        }
        int maxSame = lmax - 1;
        for(int i=lmax-1;i>=0;--i)
        {
            rSame[i] = maxSame;
            if(s1[i] != s2[i])
            {
                maxSame = i - 1;
            }
        }
        buildTree(1, 1, lmax);
        scanf("%d", &q);
        printf("Case %d:\n", cas);
        int type, index, pos;
        char s[10];
        while(q--)
        {
            scanf("%d%d",&type,&index);
            if(type == 1)
            {
                scanf("%d%s",&pos,s);
                bool isSame1 = (s1[pos] == s2[pos]);
                if(index == 1)
                {
                    s1[pos] = s[0];
                }
                else
                {
                    s2[pos] = s[0];
                }
                bool isSame2 = (s1[pos] == s2[pos]);
                if(isSame1 == isSame2)
                {
                    continue;
                }
                else
                {
                    TreeNode mid = queryTree(1, pos + 1);
                    int l = mid.lSame;
                    int r = mid.rSame;
                    int ll = l - 1 > 0 ? l - 1 : 1;
                    int rr = r + 1 < lmax ? r + 1 : lmax - 1;
                    if(isSame1)
                    {
                        updateTree(1, ll, pos, -1, pos);
                        updateTree(1, pos + 2, rr, pos + 2, -1);
                    }
                    else
                    {
                        updateTree(1, ll, pos, -1, r);
                        updateTree(1, pos + 2, rr, l, -1);
                    }
                }
            }
            else
            {
                if(s1[index] != s2[index])
                {
                    printf("0\n");
                }
                else
                {
                    TreeNode temp = queryTree(1, index + 1);
                    printf("%d\n", temp.rSame - index);
                }
            }
        }
    }
    return 0;
}
