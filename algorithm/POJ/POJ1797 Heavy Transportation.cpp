#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAX 1005
#define inf 0x7FFFFFFF

int father[MAX];
int vertexNumber,edgeNumber;

int n;
int graph[MAX][MAX];
bool visit[MAX];
int dist[MAX];
int queue[MAX], front, rear;

struct Edge
{
    int u,v,w;
}edge[MAX*MAX/2];

bool cmp(Edge a, Edge b)
{
    return a.w > b.w;
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
    memset(graph, -1, sizeof(graph));
    for(int i=0;i<edgeNumber;i++)
    {
        if(find(edge[i].u) != find(edge[i].v))
        {
            combine(edge[i].u, edge[i].v);
            graph[edge[i].u][edge[i].v]=edge[i].w;
            graph[edge[i].v][edge[i].u]=edge[i].w;
        }
    }
}

void findMin()
{
    memset(visit, false, sizeof(visit));
    dist[vertexNumber]=inf;
    queue[0] = vertexNumber;
    front = 1, rear = 0;
    visit[vertexNumber] = true;
    while(rear<front)
    {
        for(int i=1;i<=vertexNumber;i++)
        {
            if(!visit[i] && graph[queue[rear]][i]+1)
            {
                visit[i] = true;
                dist[i] = min(dist[queue[rear]], graph[queue[rear]][i]);
                if(i==1)
                {
                    return;
                }
                queue[front++]=i;
            }
        }
        ++rear;
    }
}

void input()
{
    scanf("%d%d",&vertexNumber,&edgeNumber);
    for(int i=0;i<edgeNumber;i++)
    {
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
    }
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        input();
        kruskal();
        findMin();
        printf("Scenario #%d:\n%d\n\n",i,dist[1]);
    }
	return 0;
}
