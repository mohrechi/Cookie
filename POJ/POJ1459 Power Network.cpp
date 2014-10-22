#include<stdio.h>
#include<memory.h>

int n,np,nc,m,graph[505][505],back[505],stack[505],end;

bool bfs()
{
    int start=0;
    bool visited[505];
    memset(visited, false, sizeof(visited));
    back[0]=-1;
    stack[0]=n;
    end=1;
    while(start!=end)
    {
        int i;
        for(i=0;i<=n+1;i++)
        {
            if(graph[stack[start]][i] and not visited[i])
            {
                back[end]=start;
                stack[end]=i;
                visited[i]=true;
                if(i==n+1)break;
                end++;
            }
        }
        if(i==n+1)break;
        start++;
    }
    return visited[n+1];
}

int flow()
{
    int min=0x7FFFFFFF;
    int temp=end;
    while(back[temp]!=-1)
    {
        if(graph[stack[back[temp]]][stack[temp]]<min)
        {
            min=graph[stack[back[temp]]][stack[temp]];
        }
        temp=back[temp];
    }
    temp=end;
    while(back[temp]!=-1)
    {
        graph[stack[back[temp]]][stack[temp]]-=min;
        graph[stack[temp]][stack[back[temp]]]+=min;
        temp=back[temp];
    }
    return min;
}

int main()
{
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        memset(graph,0,sizeof(graph));
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            while(getchar()!='(');
            scanf("%d,%d)%d",&u,&v,&w);
            graph[u][v]=w;
        }
        for(int i=0;i<np;i++)
        {
            int v,w;
            while(getchar()!='(');
            scanf("%d)%d",&v,&w);
            graph[n][v]=w;
        }
        for(int i=0;i<nc;i++)
        {
            int u,w;
            while(getchar()!='(');
            scanf("%d)%d",&u,&w);
            graph[u][n+1]=w;
        }
        int ans=0;
        while(bfs())
        {
            ans+=flow();
        }
        printf("%d\n",ans);
    }
    return 0;
}
