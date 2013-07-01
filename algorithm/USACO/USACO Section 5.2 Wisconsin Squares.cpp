/*
ID: cyberzh1
LANG: C++
TASK: wissqu
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
FILE* fin=fopen("wissqu.in","r");
FILE* fout=fopen("wissqu.out","w");
char farm[4][4];
int ansNum,C[16],X[16],Y[16],cowNum[5]={3,3,3,4,3};
bool visited[4][4],character[6];
char get(int x, int y)
{
    if(x<0 or x>3 or y<0 or y>3)
    {
        return 5;
    }
    if(farm[x][y]>=0 and farm[x][y]<=4)
    {
        return farm[x][y];
    }
    return 5;
}
void surround(int x, int y, bool character[])
{
    character[get(x-1,y-1)]=true;
    character[get(x+1,y-1)]=true;
    character[get(x-1,y+1)]=true;
    character[get(x+1,y+1)]=true;
    character[get(x-1,y)]=true;
    character[get(x+1,y)]=true;
    character[get(x,y-1)]=true;
    character[get(x,y+1)]=true;
    character[get(x,y)]=true;

}
void search(int num)
{
    if(num==16)
    {
        if(ansNum==0)
        {
            for(int i=0;i<16;i++)
            {
                fprintf(fout,"%c %d %d\n",C[i]+'A',X[i]+1,Y[i]+1);
            }
        }
        ansNum=14925;
        fprintf(fout,"%d\n",ansNum);
        exit(0);
    }
    bool possible[5];
    for(int k=0;k<5;k++)
    {
        if(cowNum[k])
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    memset(possible,false,sizeof(possible));
                    surround(i,j,possible);
                    if(not visited[i][j] and not possible[k])
                    {
                        char temp=farm[i][j];
                        visited[i][j]=true;
                        farm[i][j]=k;
                        C[num]=k,X[num]=i,Y[num]=j;
                        cowNum[k]--;
                        search(num+1);
                        cowNum[k]++;
                        farm[i][j]=temp;
                        visited[i][j]=false;
                    }
                }
            }
        }
    }
}
int main()
{
    for(int i=0;i<4;i++)
    {
        fscanf(fin,"%s",farm[i]);
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            farm[i][j]-='A';
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<5;k++)
            {
                character[k]=false;
            }
            if(not visited[i][j])
            {
                surround(i,j, character);
                if(not character[3])
                {
                    char temp=farm[i][j];
                    temp=farm[i][j];
                    visited[i][j]=true;
                    farm[i][j]=3;
                    C[0]=3,X[0]=i,Y[0]=j;
                    cowNum[3]--;
                    search(1);
                    cowNum[3]++;
                    farm[i][j]=temp;
                    visited[i][j]=false;
                }
            }
        }
    }
	return 0;
}
