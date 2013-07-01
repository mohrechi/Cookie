#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,n,count,temp;
    while(scanf("%d",&n)!=EOF)
    {
        a=0,b=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            a+=temp;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            b+=temp;
        }
        printf("%s\n",a>b?"YES":"NO");
    }
    return 0;
}
