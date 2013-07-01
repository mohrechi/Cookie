#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
using namespace std;
#define MAXN 5000005

struct Edge
{
    int v,w,next;
}edge[MAXN];
int intervalNumber;
int edgeNumber;
int head[MAXN];
int maxNumber, minNumber;
int dist[MAXN];
bool visit[MAXN];
int queue[MAXN],rear,front;

void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

int spfa(int start, int end)
{
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    rear = front = 0;
    visit[start] = true;
    dist[start] = 0;
    queue[front++] = start;
    while(rear<front)
    {
        int u = queue[rear];
        visit[u] = false;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(dist[u] + w > dist[v])
            {
                dist[v] = dist[u] + w;
                if(!visit[v])
                {
                    queue[front] = v;
                    visit[v] = true;
                    if(MAXN == ++front)
                    {
                        front = 0;
                    }
                }
            }
        }
        if(MAXN == ++rear)
        {
            rear = 0;
        }
    }
    return dist[end];
}

int main(int argc, char *argv[])
{
    while(~scanf("%d",&intervalNumber))
    {
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        minNumber = MAXN;
        maxNumber = -1;
        while(intervalNumber--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            minNumber = min(minNumber, a);
            maxNumber = max(maxNumber, ++b);
            addEdge(b,a,c);
        }
        for(int i=minNumber;i<maxNumber;++i)
        {
            addEdge(i+1, i, 0);
            addEdge(i, i+1, -1);
        }
        printf("%d\n",spfa(maxNumber, minNumber));
    }
    return 0;
}
