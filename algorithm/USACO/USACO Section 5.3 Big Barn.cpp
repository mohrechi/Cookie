/*
ID: cyberzh1
LANG: C++
TASK: bigbrn
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE* fin=fopen("bigbrn.in","r");
FILE* fout=fopen("bigbrn.out","w");
int n,rect[1005][1005],answer;
bool farm[1005][1005];
int min(int x, int y)
{
    return x<y?x:y;
}
int main()
{
    int x,y,m;
    fscanf(fin,"%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        farm[x][y]=true;
    }
    rect[1][1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(not farm[i][j])
            {
                rect[i][j]=min(min(rect[i-1][j], rect[i][j-1]), rect[i-1][j-1])+1;
                if(rect[i][j]>answer)
                {
                    answer=rect[i][j];
                }
            }
        }
    }
    fprintf(fout,"%d\n",answer);
	return 0;
}
