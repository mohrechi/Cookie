/*
ID: cyberzh1
LANG: C++
TASK: inflate
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("inflate.in","r");
FILE* fout=fopen("inflate.out","w");
int score[10005];
int max(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    int m,n,t,s;
    fscanf(fin,"%d%d",&m,&n);
    while(n--)
    {
        fscanf(fin,"%d%d",&s,&t);
        for(int i=t;i<=m;i++)
        {
            score[i]=max(score[i],score[i-t]+s);
        }
    }
    while(not score[m--]);
    fprintf(fout,"%d\n",score[m+1]);
}


