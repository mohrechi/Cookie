#include<stdio.h>
#include<stdlib.h>
int a[500005];
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=1;i<500005;i++) a[i]=1;
    for(int i=2;i<500005;i++)
    {
        for(int j=2;i*j<500005;j++)
        {
            a[i*j]+=i;
        }
    }
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
