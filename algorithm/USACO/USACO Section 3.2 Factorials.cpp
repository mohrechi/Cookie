/*
ID: cyberzh1
LANG: C++
TASK: fact4
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("fact4.in","r");
FILE* fout=fopen("fact4.out","w");
int main()
{
    int n;
    fscanf(fin,"%d",&n);
    int ans=1;
    int fact2=0,fact5=0;
    for(int i=1;i<=n;i++)
    {
        int temp=i;
        while((temp&1)==0)
        {
            fact2++;
            temp>>=1;
        }
        while(temp%5==0)
        {
            fact5++;
            temp/=5;
        }
        ans=(ans*temp)%10;
    }
    fact2-=fact5;
    while(fact2--)
    {
        ans=(ans*2)%10;
    }
    fprintf(fout,"%d\n",ans%10);
    return 0;
}
