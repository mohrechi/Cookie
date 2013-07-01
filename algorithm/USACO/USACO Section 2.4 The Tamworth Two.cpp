/*
ID: cyberzh1
LANG: C++
TASK: ttwo
*/
#include<stdio.h>
FILE* fin=fopen("ttwo.in","r");
FILE* fout=fopen("ttwo.out","w");
struct Creature
{
    int x, y, rotation;
}farmer, cow;
bool board[11][11];
int rotateX[]={-1,0,1,0};
int rotateY[]={0,1,0,-1};
int main()
{
    char ch;
    int step;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            fscanf(fin,"%c",&ch);
            switch (ch)
            {
                case '*': break;
                case '.': board[i][j]=true; break;
                case 'F':
                    board[i][j]=true;
                    farmer.x=i,farmer.y=j,farmer.rotation=0;
                    break;
                case 'C':
                    board[i][j]=true;
                    cow.x=i,cow.y=j,cow.rotation=0;
                    break;
                default: j--;
            }
        }
    }
    for(step=1;step<=160000;step++)
    {
        if(board[farmer.x+rotateX[farmer.rotation]][farmer.y+rotateY[farmer.rotation]])
        {
            farmer.x+=rotateX[farmer.rotation];
            farmer.y+=rotateY[farmer.rotation];
        }
        else
        {
            farmer.rotation=(farmer.rotation+1)%4;
        }
        if(board[cow.x+rotateX[cow.rotation]][cow.y+rotateY[cow.rotation]])
        {
            cow.x+=rotateX[cow.rotation];
            cow.y+=rotateY[cow.rotation];
        }
        else
        {
            cow.rotation=(cow.rotation+1)%4;
        }
        if(farmer.x==cow.x and farmer.y==cow.y)
        {
            break;
        }
    }
    if(step<=160000) fprintf(fout,"%d\n",step);
    else fprintf(fout,"0\n");
}
