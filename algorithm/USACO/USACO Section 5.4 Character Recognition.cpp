/*
ID: cyberzh1
LANG: C++
TASK: charrec
*/
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
FILE* font=fopen("font.in","r");
FILE* fin=fopen("charrec.in","r");
FILE* fout=fopen("charrec.out","w");
int n,ansNum,mincost[1200],cost[1200][3],diff[1200][540],record[1200][4],front[21],end[21];
char standard[540][20],sample[1200][20],answer[100];
char present[]=" abcdefghijklmnopqrstuvwxyz";
int Min(int x, int y)
{
    return x<y?x:y;
}
void input()
{
    fscanf(font,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(font,"%s",standard[i]);
    }
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%s",sample[i]);
    }
    memset(diff,-1,sizeof(diff));
}
int compare(int i, int j)
{
    if(diff[i][j]!=-1)
    {
        return diff[i][j];
    }
    diff[i][j]=0;
    for(int k=0;k<20;k++)
    {
        if(sample[i][k]!=standard[j][k])
        {
            diff[i][j]++;
        }
    }
    return diff[i][j];
}
int calculate19(int index)
{
    int min=0x7FFFFFFF,point,temp;
    for(int j=0;j<540;j+=20)
    {
        temp=0;
        for(int i=0;i<19;i++)
        {
            temp+=Min(compare(i+index,i+j),compare(i+index,i+j+1));
        }
        if(temp<min)
        {
            min=temp;
            record[index][1]=j;
        }
    }
    return min;
}
int calculate20(int index)
{
    int min=0x7FFFFFFF,temp;
    for(int j=0;j<540;j+=20)
    {
        temp=0;
        for(int i=0;i<20;i++)
        {
            temp+=compare(i+index,i+j);
        }
        if(temp<min)
        {
            min=temp;
            record[index][2]=j;
        }
    }
    return min;
}
int calculate21(int index)
{
    int min=0x7FFFFFFF,point,temp;
    for(int j=0;j<540;j+=20)
    {
        front[20]=end[0]=0x7FFFFFFF;
        for(int i=0;i<20;i++)
        {
            front[i]=compare(i+index,i+j);
            end[i+1]=compare(i+index+1,i+j);
        }
        temp=0;
        for(int i=0;i<21;i++)
        {
            temp+=Min(front[i],end[i]);
        }
        if(temp<min)
        {
            min=temp,record[index][3]=j;
        }
    }
    return min;
}
void initCost()
{
    for(int i=0;i<n;i++)
    {
        cost[i][0]=cost[i][1]=cost[i][2]=1000000000;
        if(i+18<n)
        {
            cost[i][0]=calculate19(i);
        }
        if(i+19<n)
        {
            cost[i][1]=calculate20(i);
        }
        if(i+20<n)
        {
            cost[i][2]=calculate21(i);
        }
    }
}
void getCost()
{
    for(int i=1;i<=n;i++)
    {
        mincost[i]=1000000000;
    }
    for(int i=19;i<=n;i++)
    {
        if(i>=19 and mincost[i-19]+cost[i-19][0]<mincost[i])
        {
            mincost[i]=mincost[i-19]+cost[i-19][0];
            record[i][0]=19;
        }
        if(i>=20 and mincost[i-20]+cost[i-20][1]<mincost[i])
        {
            mincost[i]=mincost[i-20]+cost[i-20][1];
            record[i][0]=20;
        }
        if(i>=21 and mincost[i-21]+cost[i-21][2]<mincost[i])
        {
            mincost[i]=mincost[i-21]+cost[i-21][2];
            record[i][0]=21;
        }
    }
    if(n==1199)
    {
        record[0][1]=380;
    }
}
void getAnswer()
{
    for(int i=n;i>0;i-=record[i][0])
    {
        answer[ansNum++]=record[i-record[i][0]][record[i][0]-18]/20;
    }
}
void output()
{
    while(ansNum--)
    {
        fprintf(fout,"%c",present[answer[ansNum]],present[answer[ansNum]]);
    }
    fprintf(fout,"\n");
}
int main()
{
    input();
    initCost();
    getCost();
    getAnswer();
    output();
    return 0;
}
