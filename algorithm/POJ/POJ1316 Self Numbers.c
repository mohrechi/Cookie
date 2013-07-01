#include<stdio.h>

int main()
{
    int sn=1,temp,ntemp,i;
    int a[10000];
    for(i=0;i<10000;i++) a[i]=i;
    while(sn<9974)
    {
        temp=sn;
        ntemp=sn;
        while(temp>0)
        {
            ntemp+=temp%10;
            temp/=10;
        }
        a[ntemp]=0;
        sn++;
    }
    for(i=1;i<10000;i++)
    {
        if(a[i]!=0) printf("%d\n",i);
    }
    return 0;
}
