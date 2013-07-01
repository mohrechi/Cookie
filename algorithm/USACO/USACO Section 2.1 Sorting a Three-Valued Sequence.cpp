/*
ID: cyberzh1
LANG: C++
TASK: sort3
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("sort3.in","r");
FILE* fout=fopen("sort3.out","w");
int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int min(int x, int y)
{
    return x<y?x:y;
}
int main()
{
    int n,num[1000],sort[1000];
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&num[i]);
        sort[i]=num[i];
    }
    qsort(sort,n,sizeof(int),cmp);
    int record[6]={0},result=0;
    for(int i=0;i<n;i++)
    {
        if(num[i]==1 and sort[i]==2) record[0]++;
        else if(num[i]==1 and sort[i]==3) record[1]++;
        else if(num[i]==2 and sort[i]==1) record[2]++;
        else if(num[i]==2 and sort[i]==3) record[3]++;
        else if(num[i]==3 and sort[i]==1) record[4]++;
        else if(num[i]==3 and sort[i]==2) record[5]++;
    }
    int temp;
    result+=temp=min(record[0],record[2]);
    record[0]-=temp, record[2]-=temp;
    result+=temp=min(record[1],record[4]);
    record[1]-=temp, record[4]-=temp;
    result+=temp=min(record[3],record[5]);
    record[3]-=temp, record[5]-=temp;
    result+=record[0]*2+record[1]*2;
    fprintf(fout,"%d\n",result);
    return 0;
}
