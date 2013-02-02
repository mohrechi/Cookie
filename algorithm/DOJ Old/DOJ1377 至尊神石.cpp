#include<stdio.h>
#include<stdlib.h>
struct SegTree
{
    int n,l,r;
}segTree[400005];
void build(int c, int l, int r)
{
    segTree[c].l=l;
    segTree[c].r=r;
    segTree[c].n=r-l+1;
    if(l==r) return;
    int mid=(l+r)/2;
    build(c*2,l,mid);
    build(c*2+1,mid+1,r);
}
int query(int c, int k)
{
    if(segTree[c].l==segTree[c].r) return segTree[c].l;
    if(segTree[c*2].n>=k) return query(c*2,k);
    else return query(c*2+1,k-segTree[c*2].n);
}
void del(int c, int k)
{
    segTree[c].n--;
    if(segTree[c].l==segTree[c].r) return ;
    int mid=(segTree[c].l+segTree[c].r)/2;
    if(k<= mid)del(c*2,k);
    else del(c*2+1,k);
}
int main()
{
    int n,m,w,s;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,0,n-1);
        w=1;
        s=m;
        int cur=w+s-1;
        w=cur-1;
        while(n>1)
        {
            n--;
            if(n>0)
            {
                del(1,w);
                if(n>1)printf("%d ",w+1);
                else printf("%d",w+1);
                cur=(cur+s-1)%n;
                if(cur==0)cur+=n;
                w=query(1,cur);
            }
        }
        printf("\n");
    }
    return 0;
}
