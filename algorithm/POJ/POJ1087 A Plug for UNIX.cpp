#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

int receptacleNum, deviceNum, adapterNum, graph[510][510];
char receptacle[510][30], device[510][30], devicePlug[30],adapter[2][30];
int back[510], queue[510], front, rear, in, pos[510];
bool visited[510];

int find(char s[])
{
    for(int i=0;i<receptacleNum;i++)
    {
        if(!strcmp(receptacle[i], s))
        {
            return pos[i];
        }
    }
    strcpy(receptacle[receptacleNum],s);
    pos[receptacleNum]=receptacleNum+deviceNum+2;
    return pos[receptacleNum++];
}
bool bfs()
{
    memset(visited,false,sizeof(visited));
    visited[0]=true;
    back[0]=-1, queue[0]=0, rear=0, front=1;
    while(rear<front)
    {
        for(int i=1;i<=receptacleNum+deviceNum+2;i++)
        {
            if(!visited[i] && graph[queue[rear]][i])
            {
                queue[front]=i;
                back[front]=rear;
                visited[i]=true;
                if(i==in)
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
        if(min>graph[queue[back[temp]]][queue[temp]])
        {
            min=graph[queue[back[temp]]][queue[temp]];
        }
        temp=back[temp];
    }
    while(back[front]!=-1)
    {
        graph[queue[back[front]]][queue[front]]-=min;
        graph[queue[front]][queue[back[front]]]+=min;
        front=back[front];
    }
    return min;
}
int main()
{
    scanf("%d",&receptacleNum);
    for(int i=0;i<receptacleNum;i++)
    {
        scanf("%s",receptacle[i]);
        graph[0][i+1]=1;
        pos[i]=i+1;
    }
    scanf("%d",&deviceNum);
    in=receptacleNum+deviceNum+1;
    for(int i=0;i<deviceNum;i++)
    {
        scanf("%s%s",device[i],devicePlug);
        graph[find(devicePlug)][in-deviceNum+i]=1;
        graph[in-deviceNum+i][in]=1;
    }
    scanf("%d",&adapterNum);
    for(int i=0;i<adapterNum;i++)
    {
        scanf("%s%s",adapter[0],adapter[1]);
        graph[find(adapter[1])][find(adapter[0])]=0x7FFFFFFF;
    }
    int answer=deviceNum;
    while(bfs())
    {
        answer-=flow();
    }
    printf("%d\n",answer);
    return 0;
}
