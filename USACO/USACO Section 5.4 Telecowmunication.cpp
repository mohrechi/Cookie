/*
ID: cyberzh1
LANG: C++
TASK: telecow
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
FILE* fin=fopen("telecow.in","r");
FILE* fout=fopen("telecow.out","w");
int n,m,c1,c2,graph[205][205],copy[205][205],stack[205],back[205],front,rear,answer[105],ansNum;
bool visited[205];
bool search()
{
    rear=0, front=1;
    memset(visited,false,sizeof(visited));
    stack[0]=c1+n, back[0]=-1, visited[c1+n]=true;
    while(rear<front)
    {
        for(int i=1;i<=n*2;i++)
        {
            if(not visited[i] and copy[stack[rear]][i]>0)
            {
                visited[i]=true;
                stack[front]=i;
                back[front]=rear;
                if(i==c2)
                {
                    return true;
                }
                front++;
            }
        }
        rear++;
    }
    return false;
}
int flow()
{
    int temp=front,min=0x7FFFFFFF;
    while(back[temp]!=-1)
    {
        if(copy[stack[back[temp]]][stack[temp]]<min)
        {
            min=copy[stack[back[temp]]][stack[temp]];
        }
        temp=back[temp];
    }
    while(back[front]!=-1)
    {
        copy[stack[back[front]]][stack[front]]-=min;
        copy[stack[front]][stack[back[front]]]+=min;
        front=back[front];
    }
    return min;
}
int getFlow()
{
    memcpy(copy,graph,sizeof(graph));
    int minFlow=0;
    while(search())
    {
        minFlow+=flow();
    }
    return minFlow;
}
int main()
{
    fscanf(fin,"%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=1;i<=n;i++)
    {
        graph[i][i+n]=1;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        fscanf(fin,"%d%d",&x,&y);
        graph[y+n][x]=1000000000;
        graph[x+n][y]=1000000000;
    }
    int minFlow=getFlow();
    for(int i=1;i<=n;i++)
    {
        if(i!=c1 and i!=c2)
        {
            graph[i][i+n]=0;
            int temp=getFlow();
            if(temp+1==minFlow)
            {
                answer[ansNum++]=i;
                minFlow--;
                if(not minFlow)
                {
                    break;
                }
            }
            else
            {11
                graph[i][i+n]=1;
            }
        }
    }
    fprintf(fout,"%d\n",ansNum);
    for(int i=0;i<ansNum-1;i++)
    {
        fprintf(fout,"%d ",answer[i]);
    }
    fprintf(fout,"%d\n",answer[ansNum-1]);
    return 0;
}
