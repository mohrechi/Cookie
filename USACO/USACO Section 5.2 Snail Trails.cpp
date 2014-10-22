/*
ID: cyberzh1
LANG: C++
TASK: snail
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE* fin=fopen("snail.in","r");
FILE* fout=fopen("snail.out","w");
int n,b,max;
bool visited[125][125],map[125][125];
void input()
{
    fscanf(fin,"%d %d\n",&n,&b);
    char x;
    int y;
    for(int i=0;i<b;i++)
    {
        fscanf(fin,"%c%d\n",&x,&y);
        map[y][x-'A'+1]=true;
    }
    visited[1][1]=true;
}
bool avail(int x, int y)
{
    if(x<=0 or x>n or y<=0 or y>n)
    {
        return false;
    }
    return not map[x][y] and not visited[x][y];
}
void search(int x, int y, int num, bool last)
{
    if(num>max)
    {
        max=num;
    }
    if(last)
    {
        return;
    }
    int temp;
    if(avail(x-1,y))
    {
        temp=x;
        while(avail(--temp,y));
        for(int i=x-1;i>temp;i--)
        {
            visited[i][y]=true;
            num++;
        }
        if(visited[temp][y])
        {
            search(temp+1,y,num,true);
        }
        else
        {
            search(temp+1,y,num,false);
        }
        for(int i=x-1;i>temp;i--)
        {
            visited[i][y]=false;
            num--;
        }
    }
    if(avail(x+1,y))
    {
        temp=x;
        while(avail(++temp,y));
        for(int i=x+1;i<temp;i++)
        {
            visited[i][y]=true;
            num++;
        }
        if(visited[temp][y])
        {
            search(temp-1,y,num,true);
        }
        else
        {
            search(temp-1,y,num,false);
        }
        for(int i=x+1;i<temp;i++)
        {
            visited[i][y]=false;
            num--;
        }
    }
    if(avail(x,y-1))
    {
        temp=y;
        while(avail(x,--temp));
        for(int i=y-1;i>temp;i--)
        {
            visited[x][i]=true;
            num++;
        }
        if(visited[x][temp])
        {
            search(x,temp+1,num,true);
        }
        else
        {
            search(x,temp+1,num,false);
        }
        for(int i=y-1;i>temp;i--)
        {
            visited[x][i]=false;
            num--;
        }
    }
    if(avail(x,y+1))
    {
        temp=y;
        while(avail(x,++temp));
        for(int i=y+1;i<temp;i++)
        {
            visited[x][i]=true;
            num++;
        }
        if(visited[x][temp])
        {
            search(x,temp-1,num,true);
        }
        else
        {
            search(x,temp-1,num,false);
        }
        for(int i=y+1;i<temp;i++)
        {
            visited[x][i]=false;
            num--;
        }
    }
}
int main()
{
    input();
    search(1,1,1,false);
    fprintf(fout,"%d\n",max);
	return 0;
}
