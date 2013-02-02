/*
ID: cyberzh1
LANG: C++
TASK: job
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("job.in","r");
FILE* fout=fopen("job.out","w");
int main()
{
    int n,m1,m2,time1[30],time2[30],cost1[1000],cost2[1000],delay[30];
    fscanf(fin,"%d%d%d",&n,&m1,&m2);
    for(int i=0;i<m1;i++)
    {
        fscanf(fin,"%d",&time1[i]);
    }
    for(int i=0;i<m2;i++)
    {
        fscanf(fin,"%d",&time2[i]);
    }
    for(int i=0;i<30;i++)
    {
        delay[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int min=0x7FFFFFFF,minj;
        for(int j=0;j<m1;j++)
        {
            if(delay[j]+time1[j]<min)
            {
                min=delay[j]+time1[j];
                minj=j;
            }
        }
        cost1[i]=min;
        delay[minj]+=time1[minj];
    }
    for(int i=0;i<30;i++)
    {
        delay[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int min=0x7FFFFFFF,minj;
        for(int j=0;j<m2;j++)
        {
            if(delay[j]+time2[j]<min)
            {
                min=delay[j]+time2[j];
                minj=j;
            }
        }
        cost2[i]=min;
        delay[minj]+=time2[minj];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(cost1[i]+cost2[n-i-1]>ans)
        {
            ans=cost1[i]+cost2[n-i-1];
        }
    }
    fprintf(fout,"%d %d\n",cost1[n-1],ans);
    return 0;
}
