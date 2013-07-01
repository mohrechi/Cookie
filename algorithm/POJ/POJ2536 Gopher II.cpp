#include<iostream>
#include<memory.h>
using namespace std;

struct point
{
    double x;
    double y;
}gopher[105],hole[105];

int n,m,prev[105];
bool graph[105][105],visited[105];

double calDist(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

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
    int s,v;
    double dis;
    while(cin>>n>>m>>s>>v)
    {
        dis=s*v;
        dis*=dis;
        memset(graph, false, sizeof(graph));
        for(int i=0;i<n;i++)
        {
            cin>>gopher[i].x>>gopher[i].y;
        }
        for(int i=0;i<m;i++)
        {
            cin>>hole[i].x>>hole[i].y;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(calDist(gopher[i],hole[j])<=dis)
                {
                    graph[i][j]=true;
                }
            }
        }
        cout<<n-hungary()<<endl;
    }
    return 0;
}
