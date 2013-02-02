#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int main()
{
    int a[10005],b[10005],n,count,temp;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            a[temp]++;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            b[temp]++;
        }
        count=0;
        for(int i=1;i<10000;i++)
        {
            count+=a[i]*b[10000-i];
        }
        printf("%d\n",count);
    }
    return 0;
}
