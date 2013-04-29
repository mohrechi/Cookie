#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int n,m,father[20],mat[20][20],edgeNum,count,avail[20],min,ans[20];
struct Edge
{
    int u,v,w;
}edge[300];
int cmp(const void* a, const void* b)
{
    return (*(Edge*)a).w-(*(Edge*)b).w;
}
void initUnion()
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}
int find(int i)
{
    if(father[i]==i) return i;
    return father[i]=find(father[i]);
}
void comb(int x, int y)
{
    x=find(x),y=find(y);
    father[y]=x;
}
void initEdge()
{
    edgeNum=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(avail[i] && avail[j])
            {
                edge[edgeNum].u=i, edge[edgeNum].v=j;
                edge[edgeNum].w=mat[i][j];
                edgeNum++;
            }
        }
    }
    qsort(edge,edgeNum,sizeof(*edge),cmp);
}
int kruskal()
{
    initUnion();
    int weight=0;
    for(int i=0;i<edgeNum;i++)
    {
        if(find(edge[i].u)!=find(edge[i].v))
        {
            comb(edge[i].u,edge[i].v);
            weight+=edge[i].w;
        }
    }
    return weight;
}
void search(int index,int depth)
{
    if(depth==m)
    {
        initEdge();
        int temp=kruskal();
        if(temp<min)
        {
            min=temp;
            for(int i=1;i<=n;i++)
            {
                ans[i]=avail[i];
            }
        }
        return;
    }
    for(int i=index;i<=n;i++)
    {
        avail[i]=1;
        search(i+1,depth+1);
        avail[i]=0;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        min=0x7FFFFFFF;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&mat[i][j]);
            }
        }
        search(1,0);
        int i;
        for(i=1;i<=n;i++)
        {
            if(ans[i])
            {
                printf("%d",i);
                break;
            }
        }
        for(i++;i<=n;i++)
        {
            if(ans[i])
            {
                printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
