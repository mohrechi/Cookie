#include<stdio.h>

struct Node
{
    int max,min,left,right;
}tree[200010];
int height[50010],maxHeight,minHeight;

int max(int x, int y)
{
    return x>y?x:y;
}

int min(int x, int y)
{
    return x<y?x:y;
}

void build(int left, int right, int root)
{
    tree[root].left=left;
    tree[root].right=right;
    if(left==right)
    {
        tree[root].max=tree[root].min=height[left];
    }
    else
    {
        int mid=(left+right)>>1;
        build(left,mid,root<<1);
        build(mid+1,right,(root<<1)+1);
        tree[root].max=max(tree[root<<1].max,tree[(root<<1)+1].max);
        tree[root].min=min(tree[root<<1].min,tree[(root<<1)+1].min);
    }
}

void find(int left, int right, int root)
{
    if(tree[root].left==left && tree[root].right==right)
    {
        if(tree[root].max>maxHeight)
        {
            maxHeight=tree[root].max;
        }
        if(tree[root].min<minHeight)
        {
            minHeight=tree[root].min;
        }
    }
    else
    {
        int mid=(tree[root].left+tree[root].right)>>1;
        if(mid>=right)
        {
            find(left,right,root<<1);
        }
        else if(mid<left)
        {
            find(left,right,(root<<1)+1);
        }
        else
        {
            find(left,mid,root<<1);
            find(mid+1,right,(root<<1)+1);
        }
    }
}

int main()
{
    int n,k,a,b;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&height[i]);
    }
    build(1,n,1);
    while(k--)
    {
        maxHeight=0, minHeight=0x7FFFFFFF;
        scanf("%d%d",&a,&b);
        find(a,b,1);
        printf("%d\n",maxHeight-minHeight);
    }
    return 0;
}
