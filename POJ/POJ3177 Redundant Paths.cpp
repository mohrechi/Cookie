#include<stdio.h>
#include<vector>
using namespace std;

int f,r,low[5005],visit[5005],degree[5005],count;
bool connect[5005][5005];
vector< vector<int> >adj;
int min(int x, int y)
{
    return x<y?x:y;
}
void dfs(int x, int p)
{
    visit[x]=true;
    low[x]=count++;
    int len=adj[x].size();
    for(int i=0;i<len;i++)
    {
        if(adj[x][i]==p) continue;
        if(!visit[adj[x][i]]) dfs(adj[x][i],x);
        low[x]=min(low[x],low[adj[x][i]]);
    }
}

int main()
{
    int a,b;
    scanf("%d%d",&f,&r);
    adj.assign(f+1,vector<int>());
    while(r--)
    {
        scanf("%d%d",&a,&b);
        if(!connect[a][b])
        {
            connect[a][b]=true;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    count=0;
    dfs(1,1);
    for(int i=1;i<=f;i++)
    {
        int len=adj[i].size();
        for(int j=0;j<len;j++)
        {
            if(low[i]!=low[adj[i][j]])
            {
                degree[low[i]]++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<=f;i++)
    {
        if(degree[i]==1)
        {
            ans++;
        }
    }
    printf("%d\n",(ans+1)>>1);
    return 0;
}
