/*
ID: cyberzh1
LANG: C++
TASK: numtri
*/
#include<stdio.h>
int ans[1005][1005];
int main()
{
    FILE* fin=fopen("numtri.in","r");
    FILE* fout=fopen("numtri.out","w");
    int r;
    fscanf(fin,"%d",&r);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            fscanf(fin,"%d",&ans[i][j]);
        }
    }
    for(int i=r-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            ans[i][j]+=(ans[i+1][j]>ans[i+1][j+1]?ans[i+1][j]:ans[i+1][j+1]);
        }
    }
    fprintf(fout,"%d\n",ans[1][1]);
    return 0;
}
