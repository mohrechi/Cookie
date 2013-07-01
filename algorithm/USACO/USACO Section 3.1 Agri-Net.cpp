/*
ID: cyberzh1
LANG: C++
TASK: agrinet
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("agrinet.in","r");
FILE* fout=fopen("agrinet.out","w");
int n,temp,edgeNum,field[105];
struct Edge
{
    int u,v,w;
}edge[10005];
int cmp(const void* a, const void* b)
{
    return (*(Edge*)a).w-(*(Edge*)b).w;
}
int find(int x)
{
    if(field[x]==x) return x;
    return field[x]=find(field[x]);
}
int Union(int x ,int y)
{
    x=find(x),y=find(y);
    field[y]=x;
}
int Kruskal()
{
    int count=2,result=edge[0].w;
    Union(edge[0].u,edge[0].v);
    for(int i=1;i<edgeNum;i++)
    {
        if(find(edge[i].u)!=find(edge[i].v))
        {
            Union(edge[i].u,edge[i].v);
            result+=edge[i].w;
            if(++count==n)
            {
                break;
            }
        }
    }
    return result;
}
int main()
{
    fscanf(fin,"%d",&n);
    edgeNum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(fin,"%d",&temp);
            if(j>i)
            {
                edge[edgeNum].u=i;
                edge[edgeNum].v=j;
                edge[edgeNum].w=temp;
                edgeNum++;
            }
        }
        field[i]=i;
    }
    qsort(edge,edgeNum,sizeof(*edge),cmp);
    fprintf(fout,"%d\n",Kruskal());
    return 0;
}
