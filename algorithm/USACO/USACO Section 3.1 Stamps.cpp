/*
ID: cyberzh1
LANG: C++
TASK: stamps
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("stamps.in","r");
FILE* fout=fopen("stamps.out","w");
int min[2005000];
int main()
{
    int k,n,value[50];
    fscanf(fin,"%d%d",&k,&n);
    for(int i=0;i<2005000;i++)
    {
        min[i]=300;
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&value[i]);
    }
    min[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2005000;j++)
        {
            if(min[j]<k)
            {
                if(min[j+value[i]]>1+min[j])
                {
                    min[j+value[i]]=1+min[j];
                }
            }
        }
    }
    int count=0;
    while(min[++count]<=k);
    printf("%d\n",count-1);
    fprintf(fout,"%d\n",count-1);
    return 0;
}
