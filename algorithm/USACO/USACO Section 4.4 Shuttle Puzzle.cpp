/*
ID: cyberzh1
LANG: C++
TASK: shuttle
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("shuttle.in","r");
FILE* fout=fopen("shuttle.out","w");
int main()
{
    int n,t,s,ans[500],ansNum=0;
    fscanf(fin,"%d",&n);
    for(int i=2;i<=n+1;i++)
    {
        if(i&1)
        {
            t=-2;
            s=n+i;
        }
        else
        {
            t=2;
            s=n-i+2;
        }
        ans[ansNum++]=s;
        for(int j=2;j<=i;j++)
        {
            s+=t;
            ans[ansNum++]=s;
        }
    }
    for(int i=n;i>=2;i--)
    {
        if(i&1)
        {
            t=-2;
            s=n+i;
        }
        else
        {
            t=2;
            s=n-i+2;
        }
        ans[ansNum++]=s;
        for(int j=2;j<=i;j++)
        {
            s+=t;
            ans[ansNum++]=s;
        }
    }
    ans[ansNum++]=n+1;
    for(int i=0;i<ansNum;i++)
    {
        fprintf(fout,"%d",ans[i]);
        if(i%20==19 or i==ansNum-1) fprintf(fout,"\n");
        else fprintf(fout," ");
    }
    return 0;
}
