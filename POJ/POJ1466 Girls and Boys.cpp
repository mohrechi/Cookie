#include<iostream>
#include<memory.h>
#include<stdio.h>
using namespace std;

int n,m,prev[505];
bool graph[505][505],visited[505];

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
    while(scanf("%d",&n)!=EOF)
    {
        m=n;
        memset(graph, false, sizeof(graph));
        int a,b,c;
        for(int i=0;i<n;i++)
        {
            scanf("%d: (%d)",&b,&c);
            while(c--)
            {
                scanf("%d",&a);
                graph[b][a]=true;
            }
        }
        printf("%d\n",n-hungary()/2);
    }
    return 0;
}
