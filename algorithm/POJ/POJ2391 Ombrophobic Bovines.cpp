#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxv = 205*2;
const int maxe = maxv*maxv*2;
int f,p;
int num[maxv],c[maxv];
long long g[maxv][maxv];
int sum;

struct Edge
{
    int v;
    int next;
    int flow;
};
Edge e[maxe];
int head[maxv],edgeNum;
int now[maxv],d[maxv],vh[maxv],pre[maxv],preh[maxv];

void addEdge(int a,int b,int c)
{
    e[edgeNum].v = b;
    e[edgeNum].flow = c;
    e[edgeNum].next = head[a];
    head[a] = edgeNum++;
    e[edgeNum].v = a;
    e[edgeNum].flow = 0;
    e[edgeNum].next = head[b];
    head[b] = edgeNum++;
}

void Init()
{
    edgeNum = 0;
    memset(head,-1,sizeof(head));
    memset(d,0,sizeof(d));
}

int sap(int s,int t,int n)
{
    int i,x,y;
    int f,ans = 0;
    for(i = 0; i < n; i++)
        now[i] = head[i];
    vh[0] = n;
    x = s;
    while(d[s] < n)
    {
        for(i = now[x]; i != -1; i = e[i].next)
            if(e[i].flow > 0 && d[y=e[i].v] + 1 == d[x])
                break;
            if(i != -1)
            {
                now[x] = preh[y] = i;
                pre[y] = x;
                if((x=y) == t)
                {
                    for(f = INF,i=t; i != s; i = pre[i])
                        if(e[preh[i]].flow < f)
                            f = e[preh[i]].flow;
                    ans += f;
                    do
                    {
                        e[preh[x]].flow -= f;
                        e[preh[x]^1].flow += f;
                        x = pre[x];
                    }while(x!=s);
                }
            }
            else
            {
                if(!--vh[d[x]])
                    break;
                d[x] = n;
                for(i=now[x]=head[x]; i != -1; i = e[i].next)
                {
                    if(e[i].flow > 0 && d[x] > d[e[i].v] + 1)
                    {
                        now[x] = i;
                        d[x] = d[e[i].v] + 1;
                    }
                }
                ++vh[d[x]];
                if(x != s)
                    x = pre[x];
            }
    }
    return ans;
}

void floyd()
{
    int i,j,k;
    for(k = 1; k <= f; k++)
    {
        for(i = 1; i <= f; i++)
        {
            for(j = 1; j <= f; j++)
            {
                if(k!=i&&k!=j&&i!=j&&g[i][k]+g[k][j]<g[i][j])
                    g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
}

int build(long long mid)
{
    int i,j;
    Init();
    int source = 0;
    int sink = 2*f+1;
    for(i = 1; i <= f; i++)
    {
        addEdge(source,i,num[i]);
        addEdge(i+f,sink,c[i]);
        addEdge(i,i+f,INF);
        for(j = 1; j <= f; j++)
            if(i!=j&&g[i][j]!=1000000000000&&g[i][j]<=mid)
                addEdge(i,j+f,INF);
    }
    return sap(source,sink,sink+1);
}

long long solve()
{
    long long low = 0;
    long long high = 1000000000000;
    long long mid;
    long long ans=-1;
    while(low<=high)
    {
        mid = (low+high)>>1LL;
        if(build(mid)==sum)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    int i,j;
    int a,b,w;
    scanf("%d %d",&f,&p);
    for(i = 1; i <= f; i++)
        for(j = 1; j <= f; j++)
            g[i][j] = 1000000000000;
    sum = 0;
    for(i = 1; i <= f; i++)
    {
        scanf("%d %d",&num[i],&c[i]);
        sum += num[i];
    }
    for(i = 0; i < p; i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        if(g[a][b] > w)
            g[a][b] = g[b][a] = w;
    }
    floyd();
    printf("%lld\n",solve());
    return 0;
}
