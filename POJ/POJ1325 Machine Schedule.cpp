#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

int n,m,prev[105];
bool graph[105][105],visited[105];

bool dfs(int s)
{
    for(int i=0;i<m;i++)
    {
        if(graph[s][i] and not visited[i])
        {
            visited[i]=true;
            if(prev[i]==-1 or dfs(prev[i]))
            {
                prev[i]=s;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int num=0;
    memset(prev,-1,sizeof(prev));
    for(int i=0;i<n;i++)
    {
        memset(visited,false,sizeof(visited));
        if(dfs(i))
        {
            num++;
        }
    }
    return num;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        memset(graph, false, sizeof(graph));
        int a,b,c,d;
        scanf("%d",&c);
        while(c--)
        {
            scanf("%d%d%d",&d,&a,&b);
            graph[a-1][b-1]=true;
        }
        printf("%d\n",hungary());
    }
    return 0;
}
