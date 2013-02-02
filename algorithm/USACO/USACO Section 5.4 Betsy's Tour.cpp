/*
ID: cyberzh1
LANG: C++
TASK: betsy
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("betsy.in","r");
FILE* fout=fopen("betsy.out","w");
int n,n2,visited[10][10],answer;
inline int check(int x,int y,int d)
{
    if(d==1)
    {
        if(visited[x-1][y] and not visited[x][y+1] and not visited[x][y-1])return 0;
        if(visited[x-1][y-1] and not visited[x][y-1] and not visited[x-1][y])return 0;
        if(visited[x-1][y+1] and not visited[x][y+1] and not visited[x-1][y])return 0;
    }
    else if(d==2)
    {
        if(visited[x][y-1] and not visited[x+1][y] and not visited[x-1][y])return 0;
        if(visited[x+1][y-1] and not visited[x][y-1] and not visited[x+1][y])return 0;
        if(visited[x-1][y-1] and not visited[x][y-1] and not visited[x-1][y])return 0;
    }
    else if(d==3)
    {
        if(visited[x+1][y] and not visited[x][y+1] and not visited[x][y-1])return 0;
        if(visited[x+1][y+1] and not visited[x][y+1] and not visited[x+1][y])return 0;
        if(visited[x+1][y-1] and not visited[x][y-1] and not visited[x+1][y])return 0;
    }
    else if(d==4)
    {
        if(visited[x][y+1] and not visited[x+1][y] and not visited[x-1][y])return 0;
        if(visited[x-1][y+1] and not visited[x][y+1] and not visited[x-1][y])return 0;
        if(visited[x+1][y+1] and not visited[x][y+1] and not visited[x+1][y])return 0;
    }
    return 1;
}
void search(int x, int y, int depth, int dir)
{
    if(depth==n2)
    {
        answer++;
        return ;
    }
    else
    {
        if(x==n and y==1)
        {
            return;
        }
    }
    if(not check(x,y,dir)) return;
    if(not visited[x-1][y])
    {
        visited[x-1][y]=true;
        search(x-1,y,depth+1,1);
        visited[x-1][y]=false;
    }
    if(not visited[x+1][y])
    {
        visited[x+1][y]=true;
        search(x+1,y,depth+1,3);
        visited[x+1][y]=false;
    }
    if(not visited[x][y-1])
    {
        visited[x][y-1]=true;
        search(x,y-1,depth+1,2);
        visited[x][y-1]=false;
    }
    if(not visited[x][y+1])
    {
        visited[x][y+1]=true;
        search(x,y+1,depth+1,4);
        visited[x][y+1]=false;
    }
}
int main()
{
    fscanf(fin,"%d",&n);
    n2=n*n;
    visited[1][1]=true;
    for(int i=0;i<=n+1;i++)
    {
        visited[0][i]=true;
        visited[i][0]=true;
        visited[n+1][i]=true;
        visited[i][n+1]=true;
    }
    search(1,1,1,0);
    fprintf(fout,"%d\n",answer);
    return 0;
}
