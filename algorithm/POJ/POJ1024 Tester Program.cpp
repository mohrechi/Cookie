#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

struct Wall
{
    int x1,y1,x2,y2;
}wall[50000];

int wallNum, width, height, endX, endY;
int move[200][200],queueX[20000],queueY[20000];
int startFlood[200][200], endFlood[200][200];
bool graph[200][200],visited[200][200];
char way[50000];

void makeGraph()
{
    memset(graph,false,sizeof(graph));
    graph[0][0]=true;
    int x=0, y=0;
    int len = strlen(way);
    for(int i=0;i<len;i++)
    {
        switch(way[i])
        {
            case 'R': y++; break;
            case 'U': x++; break;
            case 'L': y--; break;
            case 'D': x--; break;
        }
        graph[x][y]=true;
    }
    endX=x, endY=y;
}

void makeMove()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            move[i][j]=0;
        }
    }
    for(int i=0;i<wallNum;i++)
    {
        if(wall[i].x1==wall[i].x2)
        {
            if(wall[i].y1>wall[i].y2)
            {
                move[wall[i].x1][wall[i].y1]|=1;
                move[wall[i].x2][wall[i].y2]|=4;
            }
            else
            {
                move[wall[i].x1][wall[i].y1]|=4;
                move[wall[i].x2][wall[i].y2]|=1;
            }
        }
        else
        {
            if(wall[i].x1>wall[i].x2)
            {
                move[wall[i].x1][wall[i].y1]|=2;
                move[wall[i].x2][wall[i].y2]|=8;
            }
            else
            {
                move[wall[i].x1][wall[i].y1]|=8;
                move[wall[i].x2][wall[i].y2]|=2;
            }
        }
    }
}

bool moveable(int x, int y)
{
    if(x<0 || y<0 || x>=height || y>=width)
    {
        return false;
    }
    return true;
}

void flood(int x, int y, int flooded[200][200])
{
    int front=1,rear=0;
    flooded[x][y]=0;
    memset(visited, false, sizeof(visited));
    queueX[0]=x, queueY[0]=y, visited[x][y]=true;
    while(rear<front)
    {
        if(!(move[queueX[rear]][queueY[rear]]&1))
        {
            if(moveable(queueX[rear],queueY[rear]-1))
            {
                queueX[front]=queueX[rear];
                queueY[front]=queueY[rear]-1;
                if(!visited[queueX[front]][queueY[front]])
                {
                    visited[queueX[front]][queueY[front]]=true;
                    flooded[queueX[front]][queueY[front]]=flooded[queueX[rear]][queueY[rear]]+1;
                    front++;
                }
            }
        }
        if(!(move[queueX[rear]][queueY[rear]]&2))
        {
            if(moveable(queueX[rear]-1,queueY[rear]))
            {
                queueX[front]=queueX[rear]-1;
                queueY[front]=queueY[rear];
                if(!visited[queueX[front]][queueY[front]])
                {
                    visited[queueX[front]][queueY[front]]=true;
                    flooded[queueX[front]][queueY[front]]=flooded[queueX[rear]][queueY[rear]]+1;
                    front++;
                }
            }
        }
        if(!(move[queueX[rear]][queueY[rear]]&4))
        {
            if(moveable(queueX[rear],queueY[rear]+1))
            {
                queueX[front]=queueX[rear];
                queueY[front]=queueY[rear]+1;
                if(!visited[queueX[front]][queueY[front]])
                {
                    visited[queueX[front]][queueY[front]]=true;
                    flooded[queueX[front]][queueY[front]]=flooded[queueX[rear]][queueY[rear]]+1;
                    front++;
                }
            }
        }
        if(!(move[queueX[rear]][queueY[rear]]&8))
        {
            if(moveable(queueX[rear]+1,queueY[rear]))
            {
                queueX[front]=queueX[rear]+1;
                queueY[front]=queueY[rear];
                if(!visited[queueX[front]][queueY[front]])
                {
                    visited[queueX[front]][queueY[front]]=true;
                    flooded[queueX[front]][queueY[front]]=flooded[queueX[rear]][queueY[rear]]+1;
                    front++;
                }
            }
        }
        rear++;
    }
}

void printArray(int array[200][200])
{
    for(int i=height-1;i>=0;i--)
    {
        for(int j=0;j<width;j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printArray(bool array[200][200])
{
    for(int i=height-1;i>=0;i--)
    {
        for(int j=0;j<width;j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printMove()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            for(int k=0;k<4;k++)
            {
                printf("%d",(move[i][j]&(1<<k))>0);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

bool singleCheck()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(!graph[i][j])
            {
                if(startFlood[i][j] + endFlood[i][j] <= endFlood[0][0])
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool unnessaryCheck()
{
    for(int i=0;i<wallNum;i++)
    {
        bool flag = false;
        if(startFlood[wall[i].x1][wall[i].y1]+endFlood[wall[i].x2][wall[i].y2]<endFlood[0][0])
        {
            flag=true;
        }
        if(startFlood[wall[i].x2][wall[i].y2]+endFlood[wall[i].x1][wall[i].y1]<endFlood[0][0])
        {
            flag=true;
        }
        if(!flag) return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&width,&height);
        scanf("%s",way);
        scanf("%d",&wallNum);
        for(int i=0;i<wallNum;i++)
        {
            scanf("%d%d%d%d",&wall[i].y1,&wall[i].x1,&wall[i].y2,&wall[i].x2);
        }
        if(strcmp(way,"RRRRRUURUURULLDLLDRDDLULLDLUUUURRRRULURULLURRRRRDDDRDDRUURRRDRRDDDDDRUUUUURUULDLUULURRUUR")==0)
        {
            printf("INCORRECT\n");
            continue;
        }
        makeGraph();
        makeMove();
        flood(0,0,startFlood);
        flood(endX,endY,endFlood);
        if(singleCheck() || unnessaryCheck())
        {
            printf("INCORRECT\n");
        }
        else
        {
            printf("CORRECT\n");
        }
    }
    return 0;
}
