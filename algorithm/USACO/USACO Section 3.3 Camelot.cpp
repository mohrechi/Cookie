/*
ID: cyberzh1
LANG: C++
TASK: camelot
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
FILE* fin=fopen("camelot.in","r");
FILE* fout=fopen("camelot.out","w");
bool king[790][790],knight[790][790];
int width,height,size,knightNum,knightPos[790],kingPos;
int possible[30],possibleNum,kingConnect[790][790],knightConnect[790][790];
int queue[790],dist[790];
bool visited[790];
int kingDist[790][790],knightDist[790][790];
int kingDirx[8]={-1,-1,0,1,1,1,0,-1};
int kingDiry[8]={0,1,1,1,0,-1,-1,-1};
int knightDirx[8]={-1,-2,-2,-1,1,2,2,1};
int knightDiry[8]={-2,-1,1,2,2,1,-1,-2};
int min(int x, int y)
{
    return x<y?x:y;
}
int getPos(char x, int y)
{
    x-='A',y--;
    return x*height+y;
}
int getPos(int x, int y)
{
    return x*height+y;
}
bool inBoard(int x, int y)
{
    if(x>=0 and x<width and y>=0 and y<height)
    {
        return true;
    }
    return false;
}
int code(int x, int y)
{
    possibleNum=0;
    for(int i=-2;i<=2;i++)
    {
        for(int j=-2;j<=2;j++)
        {
            if(inBoard(x+i,y+j))
            {
                possible[possibleNum++]=getPos(x+i,y+j);
            }
        }
    }
}
void kingSPFA(int s)
{
    int rear=0,front=1;
    memset(queue,0,sizeof(queue));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<790;i++)
    {
        dist[i]=1000000000;
    }
    dist[s]=0,queue[0]=s,visited[s]=true;
    while(rear!=front)
    {
        int pRear=queue[rear];
        visited[pRear]=false;
        for(int i=1;i<=kingConnect[pRear][0];i++)
        {
            int pEdge=kingConnect[pRear][i];
            if(king[pRear][pEdge])
            {
                if(dist[pRear]+1<dist[pEdge])
                {
                    dist[pEdge]=dist[pRear]+1;
                    if(not visited[pEdge])
                    {
                        queue[front]=pEdge;
                        if(++front==790) front=0;
                        visited[pEdge]=true;
                    }
                }
            }
        }
        if(++rear==790) rear=0;
    }
    for(int i=0;i<size;i++)
    {
        kingDist[s][i]=dist[i];
    }
}
void knightSPFA(int s)
{
    int rear=0,front=1;
    memset(queue,0,sizeof(queue));
    memset(visited,false,sizeof(visited));
    for(int i=0;i<790;i++)
    {
        dist[i]=1000000000;
    }
    dist[s]=0,queue[0]=s,visited[s]=true;
    while(rear!=front)
    {
        int pRear=queue[rear];
        visited[pRear]=false;
        for(int i=1;i<=knightConnect[pRear][0];i++)
        {
            int pEdge=knightConnect[pRear][i];
            if(knight[pRear][pEdge])
            {
                if(dist[pRear]+1<dist[pEdge])
                {
                    dist[pEdge]=dist[pRear]+1;
                    if(not visited[pEdge])
                    {
                        queue[front]=pEdge;
                        if(++front==790) front=0;
                        visited[pEdge]=true;
                    }
                }
            }
        }
        if(++rear==790) rear=0;
    }
    for(int i=0;i<size;i++)
    {
        knightDist[s][i]=dist[i];
    }
}
void inputUSACO()
{
    fscanf(fin,"%d%d",&height,&width);
    size=width*height;
    char in;
    int num;
    while(fscanf(fin,"%c",&in))
    {
        if(in>='A' and in<='Z')
        {
            fscanf(fin,"%d",&num);
            kingPos=getPos(in,num);
            code(in-'A',num-1);
            break;
        }
    }
    knightNum=0;
    while(fscanf(fin,"%c",&in)!=EOF)
    {
        if(in>='A' and in<='Z')
        {
            fscanf(fin,"%d",&num);
            knightPos[knightNum]=getPos(in,num);
            knightNum++;
        }
    }
}
void init()
{
    int x,y,tx,ty;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j)
            {
                king[i][j]=knight[i][j]=true;
            }
            else
            {
                king[i][j]=knight[i][j]=false;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        kingConnect[i][0]=knightConnect[i][0]=0;
    }
    for(int i=0;i<size;i++)
    {
        x=i/height,y=i%height;
        for(int j=0;j<8;j++)
        {
            tx=x+kingDirx[j];
            ty=y+kingDiry[j];
            if(inBoard(tx,ty))
            {
                king[i][height*tx+ty]=true;
                kingConnect[i][0]++;
                kingConnect[i][kingConnect[i][0]]=height*tx+ty;
            }
            tx=x+knightDirx[j];
            ty=y+knightDiry[j];
            if(inBoard(tx,ty))
            {
                knight[i][height*tx+ty]=true;
                knightConnect[i][0]++;
                knightConnect[i][knightConnect[i][0]]=height*tx+ty;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        kingSPFA(i);
        knightSPFA(i);
    }
}
void solve()
{
    int minStep=0x7FFFFFFF,kingStep,knightStep,comStep;
    for(int i=0;i<size;i++)
    {
        knightStep=0;
        for(int j=0;j<knightNum;j++)
        {
            knightStep+=knightDist[knightPos[j]][i];
        }
        if(knightStep>=minStep) continue;
        for(int j=0;j<possibleNum;j++)
        {
            kingStep=kingDist[kingPos][possible[j]];
            comStep=1000000000;
            for(int k=0;k<knightNum;k++)
            {
                comStep=min(comStep,knightDist[knightPos[k]][possible[j]]+knightDist[possible[j]][i]-knightDist[knightPos[k]][i]);
            }
            if(knightStep+kingStep+comStep>0)
            {
                minStep=min(minStep,knightStep+kingStep+comStep);
            }
        }
    }
    fprintf(fout,"%d\n",minStep);
}
int main()
{
    inputUSACO();
    if(knightNum==0)
    {
        fprintf(fout,"0\n");
        return 0;
    }
    init();
    solve();
    return 0;
}
