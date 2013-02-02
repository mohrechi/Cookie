/*
ID: cyberzh1
LANG: C++
TASK: ditch
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("ditch.in","r");
FILE* fout=fopen("ditch.out","w");
int n,graph[205][205],path[205],back[205],front,ans;
void input()
{
    int m,s,e,c;
    fscanf(fin,"%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        fscanf(fin,"%d%d%d",&s,&e,&c);
        graph[s][e]+=c;
    }
    ans=0;
}
bool findPath()
{
    int rear=0;
    front=1;
    bool visited[205];
    for(int i=2;i<=n;i++)
    {
        visited[i]=false;
    }
    visited[1]=true,path[0]=1,back[0]=-1;
    while(rear<front)
    {
        for(int i=2;i<=n;i++)
        {
            if(not visited[i])
            {
                if(graph[path[rear]][i])
                {
                    visited[i]=true;
                    path[front]=i;
                    back[front]=rear;
                    if(i==n)
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
