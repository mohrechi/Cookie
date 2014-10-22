#include<stdio.h>
#include<stdlib.h>

struct Edge
{
    int u,v,w;
}e[5010];

int n,m,father[110];

int min(int a, int b)
{
    return a<b?a:b;
}

int max(int a, int b)
{
    return a>b?a:b;
}

int cmp(const void* a, const void* b)
{
    return (*(Edge*)a).w-(*(Edge*)b).w;
}

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
    father[y]=x;
}

int Kruskal(int start)
{
    int max=0, min=0x7FFFFFFF,count=0;
    for(int i=start;i<=m;i++)
    {
        if(findSet(e[i].u)!=findSet(e[i].v))
        {
            unionSet(e[i].u, e[i].v);
            if(e[i].w>max) max=e[i].w;
            if(e[i].w<min) min=e[i].w;
            count++;
        }
    }
    if(count!=n-1) return -1;
    return max-min;
}

int main()
{
    while(scanf("%d%d",&n,&m),n or m)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        }
        qsort(e+1,m,sizeof(*e),cmp);
        initSet();
        int slim=0x7FFFFFFF,i;
        slim=min(slim,Kruskal(1));
        if(slim!=-1)
        {
            for(i=2;i<=m;i++)
            {
                initSet();
                int temp=Kruskal(i);
                if(temp>=0)
                {
                    slim=min(slim,temp);
                }
            }
        }
        printf("%d\n",slim);
    }
    return 0;
}
