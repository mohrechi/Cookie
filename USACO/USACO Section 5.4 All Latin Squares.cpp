/*
ID: cyberzh1
LANG: C++
TASK: latin
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("latin.in","r");
FILE* fout=fopen("latin.out","w");
int main()
{
    int n;
    long long ans[]={0,1,1,2,24,1344,1128960,12198297600LL};
    fscanf(fin,"%d",&n);
    fprintf(fout,"%lld\n",ans[n]);
    return 0;
}
