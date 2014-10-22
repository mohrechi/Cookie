#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
#define inf 1000000000
#define maxn 110

struct Edge
{
    int v,val,next;
}e[maxn*maxn+100];

int box[maxn];
int n,m,mm,map[maxn][maxn];
int pre[maxn],used[maxn],q[maxn],head,end,f[maxn*maxn+100],d[maxn],id[maxn];

int min(int x,int y)
{
    return x<y?x:y;
}

int maxflow(int S,int T)
{
    int i,j,x,y,ret=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        memset(used,0,sizeof(used));
        head=0;end=0;
        q[end++]=S;
        used[S]=1;
        d[S]=inf;
        while(head<end && !used[T])
        {
            x=q[head++];
            for(i=box[x];i!=-1;i=e[i].next)
            {
                y=e[i].v;
                if(!used[y] && e[i].val>f[i])
                {
                    used[y]=1;
                    pre[y]=x;
                    id[y]=i;
                    q[end++]=y;
                    d[y]=min(d[x],e[i].val-f[i]);
                }
            }
        }
        if(!used[T])
            break;
        ret+=d[T];
        for(y=T;y!=S;y=pre[y])
        {
            i=id[y];
            f[i]+=d[T];
            if(i<m)
                f[i+m]=-f[i];
            else
                f[i-m]=-f[i];
        }
    }
    return ret;
}

int main()
{
    int i,j,x,y;
    char str[20];
    while(scanf("%d%d",&n,&mm)==2)
    {
        if(n==0 &&mm==0)
        {
            printf("0\n");
            continue;
        }
        memset(box,-1,sizeof(box));
        memset(map,0,sizeof(map));
        m=mm+n+10;
        for(i=0;i<mm;i++)
        {
            scanf("%s",str);
            sscanf(str,"(%d,%d)",&x,&y);
            x++;y++;
            map[x][y]=map[y][x]=1;
            e[i].v=y;
            e[i].val=inf;
            e[i].next=box[x+n];
            box[x+n]=i;
            e[i+m].v=x;
            e[i+m].val=inf;
            e[i+m].next=box[y+n];
            box[y+n]=i+m;
        }
        for(x=2,i=mm; x<=n ;x++,i++)
        {
            e[i].v=x+n;
            e[i].val=1;
            e[i].next=box[x];
            box[x]=i;
        }
        e[i].v=1+n;
        e[i].val=inf;
        e[i].next=box[1];
        box[1]=i;
        int ans=inf,tmp;
        for(i=2;i<=n;i++)
        {
            tmp=maxflow(1,i);
            if(ans>tmp)
                ans=tmp;
        }
        if(ans==inf)
            ans=n;
        printf("%d\n",ans);
    }
    return 0;
}
