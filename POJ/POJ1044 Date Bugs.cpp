#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;

int main()
{
    int n,m[10000],y[20],a[20],b[20],t=0,max;
    while(scanf("%d",&n),n)
    {
        memset(m,0,sizeof(m));
        max=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&y[i],&a[i],&b[i]);
            b[i]-=a[i];
            y[i]%=b[i];
            for(;y[i]<10000;y[i]+=b[i])
            {
                m[y[i]]++;
            }
            if(a[i]>max)
            {
                max=a[i];
            }
        }
        int i;
        for(i=max;i<10000;i++)
        {
            if(m[i]==n)
            {
                break;
            }
        }
        printf("Case #%d: \n",++t);
        if(i==10000)
        {
            printf("Unknown bugs detected. \n\n");
        }
        else
        {
            printf("The actual year is %d.\n\n",i);
        }
    }
    return 0;
}
