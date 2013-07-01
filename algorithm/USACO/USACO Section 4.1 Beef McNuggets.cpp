/*
ID: cyberzh1
LANG: C++
TASK: nuggets
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("nuggets.in","r");
FILE* fout=fopen("nuggets.out","w");
int main()
{
    int n,a[10];
    bool ans[200000]={false};
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&a[i]);
        if(a[i]==1)
        {
            fprintf(fout,"%d\n",0);
            return 0;
        }
        ans[a[i]]=true;
    }
    for(int i=1;i<100000;i++)
    {
        if(ans[i])
        {
            for(int j=0;j<n;j++)
            {
                ans[i+a[j]]=true;
            }
        }
    }
    int i;
    for(i=99999;i>0;i--)
    {
        if(not ans[i])
        {
            break;
        }
    }
    if(i>65535)
    {
        fprintf(fout,"0\n");
    }
    else
    {
        fprintf(fout,"%d\n",i);
    }
    return 0;
}
