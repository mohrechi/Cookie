#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXM 1005
#define MAXN 105
#define INF 1000000000

int head[MAXN], prevCustomer[MAXM];
int pigNumber[MAXM];
struct Edge
{
    int from,to,flow,next;
}edge[MAXN*MAXN*2];
int depth[MAXN];
int edgeNumber, houseNumber, customerNumber;
int sourceNode, sinkNode;

void addEdgeSub(int from, int to, int flow)
{
    edge[edgeNumber].from = from;
    edge[edgeNumber].to = to;
    edge[edgeNumber].flow = flow;
    edge[edgeNumber].next = head[from];
    head[from] = edgeNumber++;
}

void addEdge(int from, int to, int flow)
{
    addEdgeSub(from, to, flow);
    addEdgeSub(to, from, 0);
}

bool bfs(int start, int end)
{
    int front = 0, rear = 0;
    int queue[MAXN];
    memset(depth, -1, sizeof(depth));
    queue[front++] = start;
    depth[start] = 0;
    while(rear < front)
    {
        int k = queue[rear++];
        for(int i=head[k];i!=-1;i=edge[i].next)
        {
            int to = edge[i].to;
            if(-1 == depth[to] && edge[i].flow > 0)
            {
                depth[to] = depth[k] + 1;
                queue[front++] = to;
            }
        }
    }
    return -1 != depth[end];
}

int dinic(int start, int end, int sum)
{
    if(start == end)
    {
        return sum;
    }
    int temp = sum;
    for(int i=head[start];i!=-1 && sum;i=edge[i].next)
    {
        if(edge[i].flow > 0 && depth[edge[i].to] == depth[start] + 1)
        {
            int a = dinic(edge[i].to, end, min(sum, edge[i].flow));
            edge[i].flow -= a;
            edge[i^1].flow += a;
            sum -= a;
        }
    }
    return temp - sum;
}

int maxFlow(int start, int end)
{
    int result = 0;
    while(bfs(start, end))
    {
        result += dinic(start, end, INF);
    }
    return result;
}

void makeGraph()
{
    for(int i=1;i<=houseNumber;++i)
    {
        scanf("%d",&pigNumber[i]);
        prevCustomer[i] = -1;
    }
    int keyNumber, key, needs;
    for(int i=1;i<=customerNumber;++i)
    {
        scanf("%d",&keyNumber);
        for(int j=0;j<keyNumber;++j)
        {
            scanf("%d",&key);
            if(-1 == prevCustomer[key])
            {
                addEdge(sourceNode, i, pigNumber[key]);
            }
            else
            {
                addEdge(prevCustomer[key], i, INF);
            }
            prevCustomer[key] = i;
        }
        scanf("%d",&needs);
        addEdge(i, sinkNode, needs);
    }
}

int main(int argc, char *argv[])
{
    while(EOF!=scanf("%d%d",&houseNumber,&customerNumber))
    {
        edgeNumber = 0;
        sourceNode = 0;
        sinkNode = customerNumber + 1;
        for(int i=0;i<=sinkNode;++i)
        {
            head[i] = -1;
        }
        makeGraph();
        printf("%d\n",maxFlow(sourceNode, sinkNode));
    }
    return 0;
}
