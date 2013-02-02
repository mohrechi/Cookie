#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXN 105
#define MAXM 10005
#define INF 1000000000

struct Edge
{
    int to, length, next;
}edge[MAXM];
int edgeNumber, head[MAXN];
int arrayLength;
int counts[MAXN], dist[MAXN];
bool visit[MAXN];

void addEdge(int from, int to, int length)
{
    edge[edgeNumber].to = to;
    edge[edgeNumber].length = length;
    edge[edgeNumber].next = head[from];
    head[from] = edgeNumber++;
}

bool spfa()
{
    queue<int> q;
    memset(counts, 0, sizeof(counts));
    memset(visit, false, sizeof(visit));
    for(int i=0;i<=arrayLength;++i)
    {
        dist[i] = -INF;
        addEdge(arrayLength + 1, i, 0);
    }
    visit[arrayLength + 1] = true;
    q.push(arrayLength + 1);
    while(!q.empty())
    {
        int from = q.front();
        visit[from] = false;
        for(int i = head[from]; i!=-1; i = edge[i].next)
        {
            int to = edge[i].to;
            int length = edge[i].length;
            if(dist[to] < dist[from] + length)
            {
                dist[to] = dist[from] + length;
                if(!visit[to])
                {
                    visit[to] = true;
                    q.push(to);
                    if(++counts[to] > arrayLength)
                    {
                        return false;
                    }
                }
            }
        }
        q.pop();
    }
    return true;
}

int main(int argc, char *argv[])
{
    while(scanf("%d",&arrayLength), arrayLength)
    {
        int tempLength, from, to, length;
        char operate[10];
        memset(head,-1,sizeof(head));
        edgeNumber = 0;
        scanf("%d",&tempLength);
        while(tempLength--)
        {
            scanf("%d%d%s%d",&from,&to,operate,&length);
            if('g' == *operate)
            {
                addEdge(from - 1, from + to, length + 1);
            }
            else
            {
                addEdge(from + to, from - 1, 1 - length);
            }
        }
        if(spfa())
        {
            printf("lamentable kingdom\n");
        }
        else
        {
            printf("successful conspiracy\n");
        }
    }
    return 0;
}
