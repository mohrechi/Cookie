/*
ID: cyberzh1
LANG: C++
TASK: humble
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("humble.in","r");
FILE* fout=fopen("humble.out","w");
unsigned int k,n,prime[100005],humble[100005],index[100005],humbleNum;
int main()
{
    fscanf(fin,"%d%d",&k,&n);
    for(int i=0;i<k;i++)
    {
        fscanf(fin,"%d",&prime[i]);
        index[i]=0;
    }
    humble[0]=1,humbleNum=1;
    while(humbleNum<=n)
    {
        unsigned int min=0x7FFFFFFF,p=-1;
        for(int i=0;i<k;i++)
        {
            while(prime[i]*humble[index[i]]<=humble[humbleNum-1])
            {
                index[i]++;
            }
            if(prime[i]*humble[index[i]]<min)
            {
                min=prime[i]*humble[index[i]];
                p=i;
            }
        }
        humble[humbleNum++]=min;
        index[p]++;
    }
    fprintf(fout,"%d\n",humble[n]);
    return 0;
}
