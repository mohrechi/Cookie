#include<stdio.h>
#include<stdlib.h>

struct Edge
{
    int u,v,w;
}edge[50010];

int cmp(const void* a, const void* b)
{
    return (*(Edge*)b).w-(*(Edge*)a).w;
}

int caseNum, n,m, edgeNum, father[20010],answer;

void init()
{
    for(int i=0;i<n+m;i++)
    {
        father[i]=i;
    }
}

int find(int x)
{
    if(father[x]==x) return x;
    return father[x]=find(father[x]);
}

void com(int x, int y)
{
    x=find(x), y=find(y);
    father[x]=y;
}

int main()
{
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        scanf("%d%d%d",&n,&m,&edgeNum);
        for(int i=0;i<edgeNum;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
            edge[i].v+=n;
        }
        qsort(edge,edgeNum,sizeof(*edge),cmp);
        init();
        answer=(m+n)*10000;
        for(int i=0;i<edgeNum;i++)
        {
            if(find(edge[i].u)!=find(edge[i].v))
            {
                com(edge[i].u, edge[i].v);
                answer-=edge[i].w;
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
