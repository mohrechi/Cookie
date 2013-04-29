#include<stdio.h>
#include<stdlib.h>
int main()
{
    unsigned int a, b, t=1;
    scanf("%d",&a);
    while(a)
    {
        scanf("%d%",&b);
        printf("Case %d: %d\n",t++, (a+b-1)/a);
        scanf("%d",&a);
        if(a)
        {
            printf("\n");
        }
    }
    return 0;
}
