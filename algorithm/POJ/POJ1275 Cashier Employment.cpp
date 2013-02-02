#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXN 30
#define MAXM 1000

struct Edge
{
    int to,value,next;
}edge[MAXM];
int head[MAXN], edgeNumber;

void addEdge(int from, int to, int value)
{
    edge[edgeNumber].to = to;
    edge[edgeNumber].value = value;
    edge[edgeNumber].next = head[from];
    head[from] = edgeNumber++;
}

int needs[MAXN], registers[MAXN], registersNumber;
int employNumber;

void input()
{
    for(int i=1;i<=24;++i)
    {
        scanf("%d",&needs[i]);
        registers[i] = 0;
    }
    scanf("%d",&registersNumber);
    int temp;
    for(int i=0;i<registersNumber;i++)
    {
        scanf("%d",&temp);
        ++registers[++temp];
    }
}

void make()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    for(int i=1;i<=24;i++)
    {
        addEdge(i-1, i, 0);
        addEdge(i, i-1, -registers[i]);
        int j = (i + 7) % 24 + 1;
        if(i < j)
        {
            addEdge(i, j, needs[j]);
        }
        else
        {
            addEdge(i, j, needs[j] - employNumber);
        }
    }
    addEdge(0, 24, employNumber);
}

int dist[MAXN], count[MAXN];
bool visit[MAXN];
int queue[MAXM], rear, front;

bool search()
{
    for(int i=0;i<=24;++i)
    {
        dist[i] = -1000000000;
        count[i] = 0;
        visit[i] = false;
    }
    dist[0] = 0;
    front = 1, rear = 0;
    queue[0] = 0;
    visit[0] = true;
    while(rear<front)
    {
        int from = queue[rear++];
        visit[from] = false;
        for(int i=head[from];i!=-1;i=edge[i].next)
        {
            int to = edge[i].to;
            int value = edge[i].value;
            if(dist[to] < dist[from] + value)
            {
                dist[to] = dist[from] + value;
                if(!visit[to])
                {
                    visit[to] = true;
                    queue[front++] = to;
                    if(++count[to] > 24)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return dist[24] == employNumber;
}

bool solutable;

void find()
{
    solutable = false;
    for(employNumber=0;employNumber<=registersNumber;++employNumber)
    {
        make();
        if(search())
        {
            solutable = true;
            break;
        }
    }
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        input();
        find();
        if(solutable)
        {
            printf("%d\n",employNumber);
        }
        else
        {
            printf("No Solution\n");
        }
    }
    return 0;
}
