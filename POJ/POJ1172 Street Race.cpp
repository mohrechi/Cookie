#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int graph[105][205],unavoidableNum,unavoidablePoint[155],splittingNum,splittingPoint[155],pointNum;
void input()
{
    int t;
    pointNum=1;
    while(scanf("%d",&t),++t)
    {
        if(t==-1)
        {
            pointNum++;
            continue;
        }
        graph[pointNum][++graph[pointNum][0]]=t;
    }
}
void judge(int point)
{
    int depth[55],queue[55],rear=0,front=1;
    memset(depth,0,sizeof(depth));
    queue[0]=1, depth[1]=1;
    while(rear<front)
    {
        for(int i=1;i<=graph[queue[rear]][0];i++)
        {
            if(graph[queue[rear]][i]!=point and not depth[graph[queue[rear]][i]])
            {
                if(graph[queue[rear]][i]==pointNum)
                {
                    return ;
                }
                depth[graph[queue[rear]][i]]=depth[queue[rear]]+1;
                queue[front++]=graph[queue[rear]][i];
            }
        }
        rear++;
    }
    unavoidablePoint[unavoidableNum++]=point;
    bool visited[55];
    memset(visited,0,sizeof(visited));
    queue[front=1,rear=0]=point, visited[point]=true;
    while(rear<front)
    {
        for(int i=1;i<=graph[queue[rear]][0];i++)
        {
            if(depth[graph[queue[rear]][i]])
            {
                return ;
            }
            if(not visited[graph[queue[rear]][i]])
            {
                visited[graph[queue[rear]][i]]=true;
                queue[front++]=graph[queue[rear]][i];
            }
        }
        rear++;
    }
    splittingPoint[splittingNum++]=point;
}
void output()
{
    printf("%d",unavoidableNum);
    for(int i=0;i<unavoidableNum;i++)
    {
        printf(" %d",unavoidablePoint[i]-1);
    }
    printf("\n%d",splittingNum);
    for(int i=0;i<splittingNum;i++)
    {
        printf(" %d",splittingPoint[i]-1);
    }
    printf("\n");
}
int main()
{
    input();
    unavoidableNum=0, splittingNum=0;
    for(int i=2;i<pointNum;i++)
    {
        judge(i);
    }
    output();
    return 0;
}
