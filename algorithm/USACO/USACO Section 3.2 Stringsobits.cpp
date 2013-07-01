/*
ID: cyberzh1
LANG: C++
TASK: kimbits
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("kimbits.in","r");
FILE* fout=fopen("kimbits.out","w");
long long num[32][32],t;
int main()
{
    int n,l;
    fscanf(fin,"%d%d%lld",&n,&l,&t);
    for(int i=0;i<=n;i++)
    {
        num[0][i]=num[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            num[i][j]=num[i-1][j]+num[i-1][j-1];
        }
    }
    for(int i=n;i>=1;i--)
    {
        if(t>num[i-1][l])
        {
            fprintf(fout,"1");
            t-=num[i-1][l--];
        }
        else
        {
            fprintf(fout,"0");
        }
    }
    fprintf(fout,"\n");
    return 0;
}
