#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAXN 2005

int father[MAXN];
int vertexNumber,edgeNumber;
int maxLen;

struct Edge
{
    int u,v,w;
}edge[MAXN*MAXN/2];

bool cmp(const Edge a, const Edge b)
{
    return a.w < b.w;
}

void init()
{
    for(int i=1;i<=vertexNumber;i++)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if(x==father[x]) return x;
    return father[x]=find(father[x]);
}

void combine(int x, int y)
{
    x=find(x), y=find(y);
    father[x] = y;
}

void kruskal()
{
    init();
    sort(edge, edge+edgeNumber, cmp);
    for(int i=0;i<edgeNumber;i++)
    {
        if(find(edge[i].u) != find(edge[i].v))
        {
            combine(edge[i].u, edge[i].v);
            if(edge[i].w > maxLen)
            {
                maxLen = edge[i].w;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    scanf("%d%d",&vertexNumber,&edgeNumber);
    for(int i=0;i<edgeNumber;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
    maxLen = 0;
    kruskal();
    printf("%d\n",maxLen);
    return 0;
}
