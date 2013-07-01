# include<stdio.h>
# include<string.h>
# define MAXN 10005
# define MAXM 50005
struct Edge
{
    int from,to,next;
}edge1[MAXM],edge2[MAXM],edge[MAXM];
int head1[MAXN],head2[MAXN],head[MAXN],belong[MAXN],in[MAXN];
int visit1[MAXN],visit2[MAXN],visit[MAXN],val[MAXN],t[MAXN];
int bCount,tCount,tol,tol1,tol2,count;

void add(int a,int b)
{
    edge1[tol1].from=a;
    edge1[tol1].to=b;
    edge1[tol1].next=head1[a];
    head1[a]=tol1++;
    edge2[tol2].from=b;
    edge2[tol2].to=a;
    edge2[tol2].next=head2[b];
    head2[b]=tol2++;
}

void add1(int a,int b)
{
    edge[tol].from=a;
    edge[tol].to=b;
    edge[tol].next=head[a];
    head[a]=tol++;
}

void dfs1(int x)
{
    int j;
    visit1[x]=1;
    for(j=head1[x];j!=-1;j=edge1[j].next)
        if(visit1[edge1[j].to]==0)
            dfs1(edge1[j].to);
    t[tCount++]=x;
}
void dfs2(int x)
{
    int j;
    belong[x]=bCount;
    count++;
    visit2[x]=1;
    for(j=head2[x];j!=-1;j=edge2[j].next)
        if(visit2[edge2[j].to]==0)
            dfs2(edge2[j].to);
}
void dfs(int x)
{
    int i;
    visit[x]=1;
    count++;
    for(i=head[x];i!=-1;i=edge[i].next)
        if(visit[edge[i].to]==0)
            dfs(edge[i].to);
}
int main()
{
    int i,a,b,index,n,m,x,y;
    while (~scanf("%d%d",&n,&m))
    {
        tCount=0;
        bCount=0;
        tol1=0;
        tol2=0;
        for(i=0;i<=n;i++)
        {
            head1[i]=-1;
            head2[i]=-1;
            visit1[i]=0;
            visit2[i]=0;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            add(a,b);
        }
        for(i=1;i<=n;i++)
            if(visit1[i]==0)
                dfs1(i);
        for(i=tCount-1;i>=0;i--)
        {
            if(visit2[t[i]]==0)
            {
                count=0;
                dfs2(t[i]);
                val[bCount]=count;
                bCount++;
            }
        }
        for(i=0;i<bCount;i++)
        {
            in[i]=0;
            head[i]=-1;
        }
        for(i=0;i<tol1;i++)
        {
            x=belong[edge1[i].from];
            y=belong[edge1[i].to];
            if(x!=y)
            {
                in[x]++;
                add1(y,x);
            }
        }
        index=0;
        for(i=0;i<bCount;i++)
        {
            if(in[i]==0)
            {
                memset(visit,0,sizeof(visit));
                count=0;
                dfs(i);
                if(count==bCount)
                {
                    index+=val[i];
                }
            }
        }
        printf("%d\n",index);
    }
    return 0;
}
