/*
ID: cyberzh1
LANG: C++
TASK: vans
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>
FILE* fin=fopen("vans.in","r");
FILE* fout=fopen("vans.out","w");
struct BigNumber
{
    int len;
    char num[1000];
    void output()
    {
        for(int i=len-1;i>=0;i--)
        {
            fprintf(fout,"%d",num[i]);
        }
        fprintf(fout,"\n");
    }
}f[1005];
int n;
int max(int x, int y)
{
    return x>y?x:y;
}
BigNumber operator +(BigNumber a, BigNumber b)
{
    BigNumber c;
    memset(c.num,0,sizeof(c.num));
    int maxLen=max(a.len,b.len);
    for(int i=0;i<maxLen;i++)
    {
        c.num[i]+=a.num[i]+b.num[i];
        if(c.num[i]>9)
        {
            c.num[i+1]++;
            c.num[i]-=10;
        }
    }
    if(c.num[maxLen])
    {
        c.len=maxLen+1;
    }
    else
    {
        c.len=maxLen;
    }
    return c;
}
BigNumber operator -(BigNumber a, BigNumber b)
{
    BigNumber c;
    memset(c.num,0,sizeof(c.num));
    int maxLen=a.len;
    for(int i=0;i<maxLen;i++)
    {
        c.num[i]+=a.num[i]-b.num[i];
        if(c.num[i]<0)
        {
            c.num[i+1]--;
            c.num[i]+=10;
        }
    }
    for(int i=maxLen-1;i>=0;i--)
    {
        if(c.num[i])
        {
            c.len=i+1;
            break;
        }
    }
    return c;
}
int main()
{
    f[0].len=1, f[1].len=1;
    f[2].len=1, f[2].num[0]=2;
    f[3].len=1, f[3].num[0]=4;
    fscanf(fin,"%d",&n);
    for(int i=4;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2]+f[i-1]+f[i-2]+f[i-4];
        f[i]=f[i]-f[i-3]-f[i-3];
    }
    f[n].output();
	return 0;
}
