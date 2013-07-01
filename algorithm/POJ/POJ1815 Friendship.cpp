#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=1005;
const int MAXM=210000;
const int INF=1000000000;
struct Edge
{
    int st,ed;
    int next;
    int flow;
    int cap;
}edge[MAXM];
int head[MAXN],d[MAXN],hash[MAXN],map[300][300];
int value[MAXN];
int N,M,F,E;
void add(int u,int v,int w)
{
    edge[E].flow=0;
    edge[E].cap=w;
    edge[E].st=u;
    edge[E].ed=v;
    edge[E].next=head[u];
    head[u]=E++;
    edge[E].flow=0;
    edge[E].cap=0;
    edge[E].st=v;
    edge[E].ed=u;
    edge[E].next=head[v];
    head[v]=E++;
}

int dinic_bfs(int src,int dest,int ver)
{
    int i,j;
    for(i=0;i<=ver;i++)
    {
        if(hash[i])
        {
            d[i]=-2;
        }
        else d[i]=-1;
    }
    int que[MAXN],rear=1;
    que[0]=src;d[src]=0;
    for(i=0;i<rear;i++)
    {
        for(j=head[que[i]];j!=-1;j=edge[j].next)
        {
            if(d[edge[j].ed]==-1&&edge[j].cap>edge[j].flow)
            {
                d[edge[j].ed]=d[que[i]]+1;
                que[rear++]=edge[j].ed;
            }
        }
    }
    return d[dest]>=0;
}

int dinic_dfs(int src,int dest,int ver)
{
    int stk[MAXN],top=0;
    int ret=0,cur,ptr,pre[MAXN],minf,i;
    int del[MAXN],out[MAXN];
    for(i=0;i<=ver;i++)
    {
        del[i]=0,out[i]=head[i];
    }
    stk[top++]=src;
    pre[src]=src;
    cur=src;
    while(top)
    {
        while(cur!=dest&&top)
        {
            for(i=out[cur];i!=-1;i=edge[i].next)
            {
                if(d[edge[i].ed]==d[cur]+1&&edge[i].cap>edge[i].flow&&!del[edge[i].ed])
                {
                    stk[top++]=edge[i].ed;
                    cur=edge[i].ed;
                    pre[edge[i].ed]=i;
                    break;
                }
            }
            if(i==-1)
            {
                del[cur]=1;
                top--;
                if(top)cur=stk[top-1];
            }
        }
        if(cur==dest)
        {
            minf=INF;
            while(cur!=src)
            {
                cur=pre[cur];
                if(edge[cur].cap-edge[cur].flow<minf)minf=edge[cur].cap-edge[cur].flow;
                cur=edge[cur].st;
            }
            cur=dest;
            while(cur!=src)
            {
                cur=pre[cur];
                edge[cur].flow+=minf;
                edge[cur^1].flow-=minf;
                if(edge[cur].cap-edge[cur].flow==0)
                {
                    ptr=edge[cur].st;
                }
                cur=edge[cur].st;
            }
            while(top>0&&stk[top-1]!=ptr)top--;
            if(top)cur=stk[top-1];
            ret+=minf;
        }
    }
    return ret;
}

int Dinic(int src,int dest,int ver)
{
    int ret=0,t;
    while(dinic_bfs(src,dest,ver))
    {
        t=dinic_dfs(src,dest,ver);
        if(t)ret+=t;
        else break;
    }
    return ret;
}

int main()
{
    int n,s,t,i,j,w,ans,m;
    int src,dest,ver;
    while(scanf("%d%d%d",&n,&s,&t)-EOF)
    {
        m=n+n;
        ver=n+n;
        for(i=0,E=0;i<=m;i++)
        {
            head[i]=-1;
            hash[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            if(s==i)
            {
                add(s,s+n,INF);
            }
            else if(i==t)add(t,t+n,INF);
            else
            {
                add(i,i+n,1),add(i+n,i,1);
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d",&map[i][j]);
                if(map[i][j]&&i!=j&&i!=t&&j!=s)
                {
                    add(i+n,j,INF);
                }
            }
        }
        if(map[s][t])
        {
            printf("NO ANSWER!\n");
            continue;
        }
        src=s,dest=t+n;
        ans=Dinic(src,dest,ver);
        printf("%d\n",ans);
        if(ans==0)continue;
        int pre,x,k;
        for(k=1,pre=ans;k<=n;k++)
        {
            if(k==s||k==t)continue;
            for(i=0;i<E;i++)
            {
                edge[i].flow=0;
            }
            hash[k]=1;
            x=Dinic(src,dest,ver);
            if(x<pre)
            {
                pre=x;
            }
            else hash[k]=0;
        }
        int sign=0;
        for(i=1;i<=n;i++)
        {
            if(hash[i])
            {
                if(sign)printf(" ");
                printf("%d",i);
                sign=1;
            }
        }
        if(sign)printf("\n");
    }
    return 0;
}
