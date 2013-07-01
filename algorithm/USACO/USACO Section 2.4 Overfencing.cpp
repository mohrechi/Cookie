/*
ID: cyberzh1
LANG: C++
TASK: maze1
*/
#include<stdio.h>
FILE* fin=fopen("maze1.in","r");
FILE* fout=fopen("maze1.out","w");
int w,h,way[300][300],max;
bool maze[300][300],visited[300][300];
void set(int x, int y, int water)
{
    if(maze[x][y] and (water<way[x][y] or way[x][y]==0))
    {
        way[x][y]=water;
    }
}
void flood(int x, int y, int water)
{
    bool flag=true;
    way[x][y]=1;
    while(flag)
    {
        flag=false;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(way[i][j]==water)
                {
                    set(i-1,j,water+1);
                    set(i+1,j,water+1);
                    set(i,j-1,water+1);
                    set(i,j+1,water+1);
                    flag=true;
                }
            }
        }
        water++;
    }
}
int main()
{
    char ch;
    fscanf(fin,"%d%d",&w,&h);
    w=w*2+1, h=h*2+1;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;)
        {
            fscanf(fin,"%c",&ch);
            if(ch==' ')
            {
                maze[i][j]=true;
                j++;
            }
            else if(ch=='+' or ch=='-' or ch=='|')
            {
                j++;
            }
        }
    }
    max=0;
    for(int i=1;i<=h;i++)
    {
        if(maze[i][1]) flood(i,1,1);
        if(maze[i][w]) flood(i,w,1);
    }
    for(int i=1;i<=w;i++)
    {
        if(maze[1][i]) flood(1,i,1);
        if(maze[h][i]) flood(h,i,1);
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(way[i][j]>max)
            {
                max=way[i][j];
            }
        }
    }
    fprintf(fout,"%d\n",max/2);
}
