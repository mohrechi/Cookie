/*
ID: cyberzh1
LANG: C++
TASK: castle
*/
#include<stdio.h>

int m,n,roomNum,maxSize,des[60][60],cas[60][60]={0},wall[60][60]={0},value[2510];
const int Max=-1;
FILE *fin, *fout;

int findRoom(int x, int y, int num)
{
    if(cas[x][y]==0)
    {
        cas[x][y]=num;
        int count=1;
        if(not (des[x][y]&1)) count+=findRoom(x,y-1,num);
        if(not (des[x][y]&2)) count+=findRoom(x-1,y,num);
        if(not (des[x][y]&4)) count+=findRoom(x,y+1,num);
        if(not (des[x][y]&8)) count+=findRoom(x+1,y,num);
        return count;
    }
    return 0;
}

int getValue(int x, int y)
{
    if(cas[x][y]!=Max)
    {
        return value[cas[x][y]];
    }
    return 0;
}

void calcWall()
{
    int x=0,y=0,maxWall=0;
    char pos;
    for(int j=1;j<=m;j++)
    {
        for(int i=n;i>0;i--)
        {
            if(des[i][j]&1)
            {
                if(cas[i][j]!=cas[i][j-1] and value[cas[i][j]]+value[cas[i][j-1]]>maxWall)
                {
                    maxWall=value[cas[i][j]]+value[cas[i][j-1]];
                    x=i,y=j-1,pos='E';
                }
            }
            if(des[i][j]&2)
            {
                if(cas[i][j]!=cas[i-1][j] and value[cas[i][j]]+value[cas[i-1][j]]>maxWall)
                {
                    maxWall=value[cas[i][j]]+value[cas[i-1][j]];
                    x=i,y=j,pos='N';
                }
            }
            if(des[i][j]&4)
            {
                if(cas[i][j]!=cas[i][j+1] and value[cas[i][j]]+value[cas[i][j+1]]>maxWall)
                {
                    maxWall=value[cas[i][j]]+value[cas[i][j+1]];
                    x=i,y=j,pos='E';
                }
            }
            if(des[i][j]&8)
            {
                if(cas[i][j]!=cas[i+1][j] and value[cas[i][j]]+value[cas[i+1][j]]>maxWall)
                {
                    maxWall=value[cas[i][j]]+value[cas[i+1][j]];
                    x=i+1,y=j,pos='N';
                }
            }
        }
    }
    fprintf(fout,"%d\n%d %d %c\n",maxWall,x,y,pos);
}

int main()
{
    fin=fopen("castle.in","r");
    fout=fopen("castle.out","w");
    fscanf(fin,"%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fscanf(fin,"%d",&des[i][j]);
            cas[i][j]=0;
        }
    }
    roomNum=0,maxSize=0;
    int k=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            value[k]=findRoom(i,j,k);
            if(value[k]>0)
            {
                roomNum++;
                if(value[k]>maxSize)
                {
                    maxSize=value[k];
                }
            }
            k++;
        }
    }
    fprintf(fout,"%d\n%d\n",roomNum,maxSize);
    calcWall();
    return 0;
}
