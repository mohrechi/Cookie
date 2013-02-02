#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

int n,m,prev[305];
bool graph[305][305],visited[305];

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
    int t,temp,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(graph, false, sizeof(graph));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&temp);
                graph[i][temp-1]=true;
            }
        }
        if(hungary()==n)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
