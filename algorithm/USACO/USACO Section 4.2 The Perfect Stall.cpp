/*
ID: cyberzh1
LANG: C++
TASK: stall4
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("stall4.in","r");
FILE* fout=fopen("stall4.out","w");
int n,m,graph[500][500],path[500],back[500],front,ans;
void input()
{
    int num,stall;
    fscanf(fin,"%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        graph[0][i]=1;
    }
    for(int i=n+1;i<=m+n;i++)
    {
        graph[i][m+n+1]=1;
    }
    for(int i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&num);
        for(int j=1;j<=num;j++)
        {
            fscanf(fin,"%d",&stall);
            graph[i][n+stall]=1;
        }
    }
    ans=0;
}
bool findPath()
{
    int rear=0;
    front=1;
    bool visited[500];
    for(int i=1;i<=m+n+1;i++)
    {
        visited[i]=false;
    }
    visited[0]=true,path[0]=0,back[0]=-1;
    while(rear<front)
    {
        for(int i=1;i<=m+n+1;i++)
        {
            if(not visited[i])
            {
                if(graph[path[rear]][i])
                {
                    visited[i]=true;
                    path[front]=i;
                    back[front]=rear;
                    if(i==m+n+1)
                    {
                        return true;
                    }
                    front++;
                }
            }
        }
        rear++;
    }
    return false;
}
void flow()
{
    int min=0x7FFFFFFF,temp=front;
    while(back[temp]!=-1)
    {
        if(min>graph[path[back[temp]]][path[temp]])
        {
            min=graph[path[back[temp]]][path[temp]];
        }
        temp=back[temp];
    }
    while(back[front]!=-1)
    {
        graph[path[back[front]]][path[front]]-=min;
        graph[path[front]][path[back[front]]]+=min;
        front=back[front];
    }
    ans+=min;
}
void output()
{
    fprintf(fout,"%d\n",ans);
}
int main()
{
    input();
    while(findPath())
    {
        flow();
    }
    output();
    return 0;
}
