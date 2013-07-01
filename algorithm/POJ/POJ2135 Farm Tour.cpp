#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXN 1010
#define MAXM 10010
#define INF 0x3F3F3F3F

struct Node
{
    int u,v,f,c;
    int prev;
}edge[MAXM*4];

int n,m,edgeNumber;
int prev[MAXN],dist[MAXN],queue[MAXM],head[MAXN];
bool visit[MAXN];

void addEdgePart(int u, int v, int f, int c)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].f = f;
    edge[edgeNumber].c = c;
    edge[edgeNumber].prev = head[u];
    head[u] = edgeNumber ++;
}

void addEdge(int u, int v, int f, int c)
{
    addEdgePart(u, v, f, c);
    addEdgePart(v, u, 0, -c);
}

bool SPFA(int start, int end)
{
    int front = 1,rear = 0;
    memset(visit,false,sizeof(visit));
    memset(prev,-1,sizeof(prev));
    memset(dist, INF, sizeof(dist));
    queue[0] = start;
    visit[start] = true;
    dist[start] = 0;
    while(rear<front)
    {
        int r = queue[rear++];
        visit[r] = false;
        for(int p=head[r];p!=-1;p=edge[p].prev)
        {
            int k=edge[p].v;
            if(edge[p].f!=0 && dist[k]>dist[r]+edge[p].c)
            {
                dist[k] = dist[r] + edge[p].c;
                prev[k] = p;
                if(!visit[k])
                {
                    visit[k] = true;
                    queue[front++] = k;
                }
            }
        }
    }
    return prev[end]!=-1;
}

int MCMF(int start, int end)
{
    int ans=0;
    while(SPFA(start, end))
    {
        ans+=dist[end];
        int p = prev[end];
        while(p!=-1)
        {
            edge[p].f--;
            edge[p^1].f++;
            p=prev[edge[p].u];
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
	scanf("%d%d",&n,&m);
	edgeNumber = 0;
	memset(head,-1,sizeof(head));
	int u,v,c;
	for(int i=0;i<m;i++)
	{
	    scanf("%d%d%d",&u,&v,&c);
	    addEdge(u,v,1,c);
	    addEdge(v,u,1,c);
	}
	addEdge(0,1,2,0);
	addEdge(n,n+1,2,0);
	printf("%d\n",MCMF(0,n+1));
	return 0;
}
