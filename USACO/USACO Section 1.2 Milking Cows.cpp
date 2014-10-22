/*
ID: cyberzh1
LANG: C++
TASK: milk2
*/
#include<stdio.h>
#include<stdlib.h>

struct period
{
    int start,end;
}p[5010];

int cmp(const void* a, const void* b)
{
    return (*(period*)a).start-(*(period*)b).start;
}

int main()
{
    FILE* fin  = fopen("milk2.in","r");
    FILE* fout = fopen("milk2.out","w");
    int n,continuous=0,idle=0,max=0;
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d%d",&p[i].start,&p[i].end);
        if(p[i].end>max)
        {
            max=p[i].end;
        }
    }
    qsort(p,n,sizeof(*p),cmp);
    int start,end;
    start=p[0].start,end=p[0].end;
    for(int i=0;i<n;i++)
    {
        if(p[i].start<=end)
        {
            if(p[i].end>end)
            {
                end=p[i].end;
            }
        }
        else
        {
            int temp=end-start;
            if(temp>continuous)
            {
                continuous=temp;
            }
            temp=p[i].start-end;
            if(temp>idle)
            {
                idle=temp;
            }
            start=p[i].start;
            end=p[i].end;
        }
    }
    int temp=end-start;
    if(temp>continuous)
    {
        continuous=temp;
    }
    fprintf(fout,"%d %d\n",continuous,idle);
    return 0;
}
