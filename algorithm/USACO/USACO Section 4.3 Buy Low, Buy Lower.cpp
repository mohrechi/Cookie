/*
ID: cyberzh1
LANG: C++
TASK: buylow
*/
#include<stdio.h>
#include<stdlib.h>
FILE* fin=fopen("buylow.in","r");
FILE* fout=fopen("buylow.out","w");
int min(int a, int b)
{
    return a<b?a:b;
}
int max(int a, int b)
{
    return a>b?a:b;
}
struct BigNumber
{
    int len;
    int num[100];
    BigNumber()
    {
        len=1;
        for(int i=0;i<100;i++)
        {
            num[i]=0;
        }
    }
    void output()
    {
        for(int i=len-1;i>=0;i--)
        {
            fprintf(fout,"%d",num[i]);
        }
        fprintf(fout,"\n");
    }
};
BigNumber operator +(BigNumber a, BigNumber b)
{
    BigNumber c;
    c.len=max(a.len,b.len);
    for(int i=0;i<c.len;i++)
    {
        c.num[i]=a.num[i]+b.num[i]+c.num[i];
        if(c.num[i]>9)
        {
            c.num[i]%=10;;
            c.num[i+1]=1;
        }
    }
    if(c.num[c.len])
    {
        c.len++;
    }
    return c;
}
int n,price[5000],maxDec[5000],next[5000];
BigNumber count[5000];
int main()
{
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%d",&price[i]);
    }
    price[n++]=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(price[i]==price[j])
            {
                next[i]=j;
                break;
            }
        }
    }
    maxDec[0]=1;
    count[0].num[0]=1;
    int maxD=0,p=0;
    for(int i=1;i<n;i++)
    {
        maxDec[i]=1;
        count[i].num[0]=1;
        for(int j=0;j<i;j++)
        {
            if(next[j] and next[j]<i)
            {
                continue;
            }
            if(price[j]>price[i])
            {
                if(maxDec[j]+1>maxDec[i])
                {
                    maxDec[i]=maxDec[j]+1;
                    count[i]=count[j];
                }
                else if(maxDec[j]+1==maxDec[i])
                {
                    count[i]=count[i]+count[j];
                }
            }
        }
        if(maxDec[i]>=maxD)
        {
            maxD=maxDec[i];
            p=i;
        }
    }
    fprintf(fout,"%d ",maxD-1);
    count[p].output();
    return 0;
}
