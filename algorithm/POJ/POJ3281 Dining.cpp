#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;
#define MAXN 405
#define MAXP 401
#define inf 100000000
int graph[MAXN][MAXN];
int depth[MAXN];
int n,f,d;

void initGraph()
{
    scanf("%d%d%d",&n,&f,&d);
    memset(graph,0,sizeof(graph));
    for(int i=1;i<=n;i++)
    {
        graph[100+i][200+i]=1;
    }
    for(int i=1;i<=f;i++)
    {
        graph[0][i]=true;
    }
    for(int i=1;i<=d;i++)
    {
        graph[300+i][401]=1;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&f,&d);
        int t;
        while(f--)
        {
            scanf("%d",&t);
            graph[t][100+i]=1;
        }
        while(d--)
        {
            scanf("%d",&t);
            graph[200+i][300+t]=1;
        }
    }
}

bool bfs(int start, int end)
{
    int front=0,rear=0;
    int queue[MAXN];
    memset(depth,-1,sizeof(depth));
    queue[rear++]=start;
    depth[start]=0;
    while(front<rear)
    {
        int k=queue[front++];
        for(int i=0;i<=MAXP;i++)
        {
            if(graph[k][i]>0 && depth[i]==-1)
            {
                depth[i]=depth[k]+1;
                queue[rear++]=i;
            }
        }
    }
    if(depth[end]>=0)
    {
        return true;
    }
    return false;
}

int dinic(int start, int end, int sum)
{
    if(start==end)
    {
        return sum;
    }
    int temp=sum;
    for(int i=0;i<=MAXP && sum;i++)
    {
        if(depth[i]==depth[start]+1 && graph[start][i]>0)
        {
            int a=dinic(i, end, min(sum,graph[start][i]));
            graph[start][i]-=a;
            graph[i][start]+=a;
            sum-=a;
        }
    }
    return temp-sum;
}

int maxflow(int start, int end)
{
    int ret = 0;
    while(bfs(start, end))
    {
        ret += dinic(start, end, inf);
    }
    return ret;
}

int main(int argc, char *argv[])
{
	initGraph();
	printf("%d\n",maxflow(0,401));
	return 0;
}
