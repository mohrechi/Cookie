#include <iostream>
#include <stdio.h>
#include <memory.h>
using namespace std;

bool graph[405][405], visit[405];
int link[405];
int n,m;
int tempGraph[405][405];
int dirX[4]={0,1,0,-1};
int dirY[4]={1,0,-1,0};
int cityNumber;

bool find(int a)
{
    for(int i=1;i<=m;i++)
    {
        if(graph[a][i]==1&&!visit[i])
        {
            visit[i]=true;
            if(link[i]==0||find(link[i]))
            {
                link[i]=a;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans=0;
    memset(link, 0, sizeof(link));
    for(int i=1;i<=n;i++)
    {
        memset(visit, false, sizeof(visit));
        if(find(i))
        {
            ++ans;
        }
    }
    return ans;
}

void input()
{
    memset(tempGraph, 0, sizeof(tempGraph));
    scanf("%d%d",&n,&m);
    char s[50];
    cityNumber=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        for(int j=1;j<=m;j++)
        {
            if(s[j]=='o')
            {
                tempGraph[i][j]=0;
            }
            else
            {
                tempGraph[i][j]=++cityNumber;
            }
        }
    }
}

void makeGraph()
{
    memset(graph, false, sizeof(graph));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(tempGraph[i][j])
            {
                for(int k=0;k<4;k++)
                {
                    if(tempGraph[i+dirX[k]][j+dirY[k]])
                    {
                        graph[tempGraph[i][j]][tempGraph[i+dirX[k]][j+dirY[k]]]=true;
                    }
                }
            }
        }
    }
    n=m=cityNumber;
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        input();
        makeGraph();
        printf("%d\n",n-(hungary()>>1));
    }
	return 0;
}
