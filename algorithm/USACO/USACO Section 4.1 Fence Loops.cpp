/*
ID: cyberzh1
LANG: C++
TASK: fence6
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("fence6.in","r");
FILE* fout=fopen("fence6.out","w");
int graph[105][105],n,fence[105],perimeter,lconn[105][105],rconn[105][105];
int min(int x, int y)
{
    return x<y?x:y;
}
void input()
{
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        int s,t;
        fscanf(fin,"%d",&s);
        fscanf(fin,"%d%d%d",&fence[s],&lconn[s][0],&rconn[s][0]);
        for(int j=1;j<=lconn[s][0];j++)
        {
            fscanf(fin,"%d",&lconn[s][j]);
        }
        for(int j=1;j<=rconn[s][0];j++)
        {
            fscanf(fin,"%d",&rconn[s][j]);
        }
    }
}
void initGraph()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j]=700000000;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=lconn[i][0];j++)
        {
            graph[i][lconn[i][j]]=fence[i]+fence[lconn[i][j]];
        }
        for(int j=1;j<=rconn[i][0];j++)
        {
            graph[i][rconn[i][j]]=fence[i]+fence[rconn[i][j]];
        }
    }
}
void floyed()
{
    int dist[105][105];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[i][j]=graph[i][j];
        }
    }
    perimeter=700000000;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=lconn[k][0];i++)
        {
            if(lconn[k][i]>=k)
            {
                continue;
            }
            for(int j=1;j<=rconn[k][0];j++)
            {
                if(rconn[k][j]>=k)
                {
                    continue;
                }
                perimeter=min(perimeter,dist[lconn[k][i]][rconn[k][j]]+graph[k][lconn[k][i]]+graph[k][rconn[k][j]]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}
void output()
{
    fprintf(fout,"%d\n",perimeter/2);
}
int main()
{
    input();
    initGraph();
    floyed();
    output();
    return 0;
}
