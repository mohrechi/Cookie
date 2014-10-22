#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,n,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        b=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            b+=a;
        }
        printf("%d\n",b);
    }
    return 0;
}
