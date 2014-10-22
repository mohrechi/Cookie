/*
ID: cyberzh1
LANG: C++
TASK: holstein
*/
#include<stdio.h>
int main()
{
    FILE* fin=fopen("holstein.in","r");
    FILE* fout=fopen("holstein.out","w");
    int v,require[25],g,scoop[1000][25];
    fscanf(fin,"%d",&v);
    for(int i=0;i<v;i++)
    {
        fscanf(fin,"%d",&require[i]);
    }
    fscanf(fin,"%d",&g);
    for(int i=0;i<g;i++)
    {
        for(int j=0;j<v;j++)
        {
            fscanf(fin,"%d",&scoop[i][j]);
        }
    }
    int max,min,point,count[25];
    max=(1<<g)-1,min=0x7FFFFFFF;
    for(int i=max;i>0;i--)
    {
        int j,num=0;
        for(int k=0;k<g;k++)
        {
            if(i&(1<<k))
            {
                num++;
            }
        }
        if(num>=min)
        {
            continue;
        }
        for(j=0;j<v;j++)
        {
            count[j]=0;
            for(int k=0;k<g;k++)
            {
                if(i&(1<<k))
                {
                    count[j]+=scoop[k][j];
                }
            }
            if(count[j]<require[j])
            {
                break;
            }
        }
        if(j==v)
        {
            min=num;
            point=i;
        }
    }
    fprintf(fout,"%d",min);
    for(int i=0;i<g;i++)
    {
        if(point&(1<<i))
        {
            fprintf(fout," %d",i+1);
        }
    }
    fprintf(fout,"\n");
    return 0;
}
