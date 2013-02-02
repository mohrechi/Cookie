#include<stdio.h>

int L,T,O,color;
struct Node
{
    int l,r,color;
    bool single()
    {
        for(int i=0;i<T;i++)
        {
            if(color==(1<<i))
            {
                return true;
            }
        }
        return false;
    }
}tree[400010];

void build(int l, int r, int root)
{
    tree[root].l=l, tree[root].r=r, tree[root].color=1;
    if(l!=r)
    {
        int mid=(l+r)>>1;
        build(l,mid,root<<1);
        build(mid+1,r,(root<<1)+1);
    }
}

void insert(int l, int r, int root, int c)
{
    if(l<=tree[root].l && tree[root].r<=r)
    {
        tree[root].color=c;
        return;
    }
    if(tree[root].single())
    {
        tree[root<<1].color=tree[(root<<1)+1].color=tree[root].color;
    }
    int mid=(tree[root].l+tree[root].r)>>1;
    if(mid>=l) insert(l,r,root<<1,c);
    if(mid<r) insert(l,r,(root<<1)+1,c);
    tree[root].color=tree[root<<1].color | tree[(root<<1)+1].color;
}

void find(int l, int r, int root)
{
    if(l<=tree[root].l && tree[root].r<=r)
    {
        color|=tree[root].color;
        return;
    }
    if(tree[root].single())
    {
        color|=tree[root].color;
        return;
    }
    int mid=(tree[root].l+tree[root].r)>>1;
    if(mid>=l) find(l,r,root<<1);
    if(mid<r) find(l,r,(root<<1)+1);
}

int calc(int c)
{
    int count=0;
    for(int i=0;i<T;i++)
    {
        if(c&(1<<i))
        {
            count++;
        }
    }
    return count;
}

void check(int &x, int &y)
{
    if(x>y)
    {
        x^=y,y^=x,x^=y;
    }
}
int main()
{
    scanf("%d%d%d",&L,&T,&O);
    char ope[10];
    int a,b,c;
    build(1,L,1);
    while(O--)
    {
        scanf("%s",ope);
        if(*ope=='C')
        {
            scanf("%d%d%d",&a,&b,&c);
            c=1<<(c-1);
            check(a,b);
            insert(a,b,1,c);
        }
        else
        {
            scanf("%d%d",&a,&b);
            color=0;
            check(a,b);
            find(a,b,1);
            c=calc(color);
            printf("%d\n",c);
        }
    }
    return 0;
}
