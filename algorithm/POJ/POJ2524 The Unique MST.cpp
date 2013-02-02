#include<stdio.h>
#include<stdlib.h>

struct Edge
{
    int u,v,w;
}e[10005];

int father[105],n,m,top,connectable[10005];

void initSet()
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}

int findSet(int x)
{
    if(father[x]==x) return x;
    return father[x]=findSet(father[x]);
}

void unionSet(int x, int y)
{
    x=findSet(x);
    y=findSet(y);
    if(x!=y)
    {
        father[y]=x;
    }
}

int cmp(const void* a, const void* b)
{
    return (*(Edge*)a).w-(*(Edge*)b).w;
}

int Kruskal(int unavailable)
{
    int res=0,count=0;
    for(int i=1;i<=m;i++)
    {
        if(i!=unavailable)
        {
            if(findSet(e[i].u)!=findSet(e[i].v))
            {
                unionSet(e[i].u,e[i].v);
                res+=e[i].w;
                count++;
                if(not unavailable)
                {
                    connectable[top++]=i;
                }
            }
        }
    }
    if(count!=n-1) return 0x7FFFFFFF;
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
            connectable[i]=false;
        }
        qsort(e+1,m,sizeof(*e),cmp);
        initSet();
        top=0;
        int min=Kruskal(0);
        int i;
        for(i=0;i<top;i++)
        {
            initSet();
            if(min>=Kruskal(connectable[i]))
            {
                break;
            }
        }
        if(i!=top) printf("Not Unique!\n");
        else printf("%d\n",min);
    }
    return 0;
}
