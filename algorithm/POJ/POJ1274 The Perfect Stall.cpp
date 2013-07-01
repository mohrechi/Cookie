#include<stdio.h>
#include<memory.h>

int n,m,g[405][405],stack[405],back[405],end;

bool bfs()
{
    bool visited[405];
    memset(visited, false, sizeof(visited));
    int start=0;
    end=1;
    stack[0]=0, back[0]=-1,visited[0]=true;
    while(start<=end)
    {
        for(int i=1;i<=m+n+1;i++)
        {
            if(g[stack[start]][i] and not visited[i])
            {
                visited[i]=true;
                stack[end]=i;
                back[end]=start;
                if(i==m+n+1)
                {
                    return true;
                }
                end++;
            }
        }
        start++;
    }
    return false;
}

int flow()
{
    int min=0x7FFFFFFF;
    int t=end;
    while(back[t]!=-1)
    {
        if(g[stack[back[t]]][stack[t]]<min)
        {
            min=g[stack[back[t]]][stack[t]];
        }
        t=back[t];
    }
    while(back[end]!=-1)
    {
        g[stack[back[end]]][stack[end]]-=min;
        g[stack[end]][stack[back[end]]]+=min;
        end=back[end];
    }
    return min;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            while(t--)
            {
                int s;
                scanf("%d",&s);
                g[i][s+n]=1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            g[0][i]=1;
        }
        for(int i=n+1;i<=m+n;i++)
        {
            g[i][m+n+1]=1;
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
