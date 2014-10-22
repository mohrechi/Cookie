/*
ID: cyberzh1
LANG: C++
TASK: castle
*/
#include<stdio.h>

int m,n,roomNum,maxSize,des[60][60],cas[60][60]={0},value[2510];
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

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&des[i][j]);
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
    printf("%d\n%d\n",roomNum,maxSize);
    return 0;
}
