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
        while(n--)
        {
            scanf("%d",&a);
            b+=a;
        }
        printf("%d\n",b);
        if(t) printf("\n");
    }
    return 0;
}
