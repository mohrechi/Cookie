/*
ID: cyberzh1
LANG: C++
TASK: money
*/
#include<stdio.h>
FILE* fin=fopen("money.in","r");
FILE* fout=fopen("money.out","w");
int main()
{
    int n,v,money[30];
    long long way[10005]={0};
    fscanf(fin,"%d%d",&v,&n);
    way[0]=1;
    for(int i=0;i<v;i++)
    {
        fscanf(fin,"%d",&money[i]);
        for(int j=money[i];j<=n;j++)
        {
            way[j]+=way[j-money[i]];
        }
    }
    fprintf(fout,"%lld\n",way[n]);
    return 0;
}
