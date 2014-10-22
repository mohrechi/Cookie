#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int width,height,knightNum,knightPos[64],kingPos,king[64][64],knight[64][64];
int kingDirx[8]={-1,-1,0,1,1,1,0,-1};
int kingDiry[8]={0,1,1,1,0,-1,-1,-1};
int knightDirx[8]={-1,-2,-2,-1,1,2,2,1};
int knightDiry[8]={-2,-1,1,2,2,1,-1,-2};
int min(int x, int y)
{
    return x<y?x:y;
}
int getPos(char x, char y)
{
    x-='A',y-='1';
    return x*width+y;
}
bool inBoard(int x, int y)
{
    if(x>=0 and x<width and y>=0 and y<height)
    {
        return true;
    }
    return false;
}
void Floyd(int array[][64])
{
    for(int k=0;k<64;k++)
    {
        for(int i=0;i<64;i++)
        {
            for(int j=0;j<64;j++)
            {
                if(array[i][k]+array[k][j]<array[i][j])
                {
                    array[i][j]=array[i][k]+array[k][j];
                }
            }
        }
    }
}
void inputPOJ()
{
    width=height=8;
    char s[200];
    scanf("%s",s);
    kingPos=getPos(s[0],s[1]);
    knightNum=0;
    int len=strlen(s);
    for(int i=2;i<len;i+=2)
    {
        knightPos[knightNum]=getPos(s[i],s[i+1]);
        knightNum++;
    }
}
void init()
{
    int x,y,tx,ty;
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            if(i==j)
            {
                king[i][j]=knight[i][j]=0;
            }
            else
            {
                king[i][j]=knight[i][j]=1000000000;
            }
        }
    }
    for(int i=0;i<64;i++)
    {
        x=i/8,y=i%8;
        for(int j=0;j<8;j++)
        {
            tx=x+kingDirx[j];
            ty=y+kingDiry[j];
            if(inBoard(tx,ty))
            {
                king[i][8*tx+ty]=1;
            }
            tx=x+knightDirx[j];
            ty=y+knightDiry[j];
            if(inBoard(tx,ty))
            {
                knight[i][8*tx+ty]=1;
            }
        }
    }
    Floyd(king);
    Floyd(knight);
}
void solve()
{
    int minStep=0x7FFFFFFF,kingStep,knightStep,comStep;
    for(int i=0;i<64;i++)
    {
        knightStep=0;
        for(int j=0;j<knightNum;j++)
        {
            knightStep+=knight[knightPos[j]][i];
        }
        for(int j=0;j<64;j++)
        {
            kingStep=king[kingPos][j];
            comStep=1000000000;
            for(int k=0;k<knightNum;k++)
            {
                comStep=min(comStep,knight[knightPos[k]][j]+knight[j][i]-knight[knightPos[k]][i]);
            }
            minStep=min(minStep,knightStep+kingStep+comStep);
        }
    }
    printf("%d\n",minStep);
}
int main()
{
    inputPOJ();
    init();
    solve();
    return 0;
}
