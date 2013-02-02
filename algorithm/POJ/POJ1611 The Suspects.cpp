#include<stdio.h>

int father[30005],num[30005],n,m;

void initSet()
{
    for(int i=0;i<n;i++)
    {
        father[i]=i;
        num[i]=1;
    }
}

int findSet(int x)
{
    if(x==father[x]) return x;
    else return father[x]=findSet(father[x]);
}

void unionSet(int x, int y)
{
    x=findSet(x);
    y=findSet(y);
    if(x!=y)
    {
        father[y]=x;
        num[x]+=num[y];
    }
}

int main()
{
    while(scanf("%d%d",&n,&m),n or m)
    {
        initSet();
        while(m--)
        {
            int k,x,y;
            scanf("%d%d",&k,&x);
            while(--k)
            {
                scanf("%d",&y);
                unionSet(x,y);
            }
        }
        printf("%d\n",num[findSet(0)]);
    }
    return 0;
}
