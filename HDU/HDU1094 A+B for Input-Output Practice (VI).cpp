#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        b=0;
        while(n--)
        {
            scanf("%d",&a);
            b+=a;
        }
        printf("%d\n",b);
    }
    return 0;
}
