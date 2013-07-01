/*
ID: cyberzh1
LANG: C++
TASK: barn1
*/
#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    FILE* fin=fopen("barn1.in","r");
    FILE* fout=fopen("barn1.out","w");
    int m,s,c,min=300,max=0,len;
    bool a[205]={false};
    fscanf(fin,"%d%d%d",&m,&s,&c);
    for(int i=0;i<c;i++)
    {
        int temp;
        fscanf(fin,"%d",&temp);
        a[temp]=true;
        if(temp>max) max=temp;
        if(temp<min) min=temp;
    }
    len=max-min+1;
    int b[205],k=0;
    for(int i=min;i<max;i++)
    {
        for(int j=i+1;j<=max;j++)
        {
            if(a[j])
            {
                b[k++]=j-i-1;
                i=j-1;
                break;
            }
        }
    }
    qsort(b,k,sizeof(int),cmp);
    while(--m)
    {
        len-=b[--k];
        if(not k)break;
    }
    fprintf(fout,"%d\n",len);
    return 0;
}
