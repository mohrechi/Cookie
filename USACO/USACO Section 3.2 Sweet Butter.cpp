/*
ID: cyberzh1
LANG: C++
TASK: butter
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
FILE* fin=fopen("butter.in","r");
FILE* fout=fopen("butter.out","w");
int cowNum,farmNum,edgeNum,cowPos[510],minDist,graph[1000][1000],connect[1000][1000];
int queue[1000],dist[1000],rear,front,record[1000][1000],count[1000];
bool visited[1000];
void SPFA(int s)
{
    rear=0,front=1;
    memset(queue,0,sizeof(queue));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<801;i++)
    {
        dist[i]=1000000000;
    }
    for(int i=1;i<=s;i++)
    {
        dist[i]=record[i][s];
        visited[i]=true;
        queue[front++]=i;
    }
    dist[s]=0,queue[0]=s,visited[s]=true;
    while(rear!=front)
    {
        int pRear=queue[rear];
        visited[pRear]=false;
        for(int i=1;i<=connect[pRear][0];i++)
        {
            int pEdge=connect[pRear][i];
            if(dist[pRear]+graph[pRear][pEdge]<dist[pEdge])
            {
                dist[pEdge]=dist[pRear]+graph[pRear][pEdge];
                if(not visited[pEdge])
                {
                    queue[front]=pEdge;
                    if(++front==1000) front=0;
                    visited[pEdge]=true;
                }
            }
        }
        if(++rear==1000) rear=0;
    }
    int min=0;
    for(int i=0;i<cowNum;i++)
    {
        min+=dist[cowPos[i]];
    }
    if(min<minDist)
    {
        minDist=min;
    }
    for(int i=1;i<=farmNum;i++)
    {
        record[s][i]=dist[i];
    }
}

int main()
{
    fscanf(fin,"%d%d%d",&cowNum,&farmNum,&edgeNum);
    for(int i=0;i<cowNum;i++)
    {
        fscanf(fin,"%d",&cowPos[i]);
    }
    for(int i=1;i<=farmNum;i++)
    {
        for(int j=1;j<=farmNum;j++)
        {
            graph[i][j]=1000000000;
        }
    }
    for(int i=0;i<edgeNum;i++)
    {
        int a,b,c;
        fscanf(fin,"%d%d%d",&a,&b,&c);
        connect[a][0]++,connect[a][connect[a][0]]=b,graph[a][b]=c;
        connect[b][0]++,connect[b][connect[b][0]]=a,graph[b][a]=c;
    }
    minDist=0x7FFFFFFF;
    for(int i=1;i<=farmNum;i++)
    {
        SPFA(i);
    }
    fprintf(fout,"%d\n",minDist);
    return 0;
}
