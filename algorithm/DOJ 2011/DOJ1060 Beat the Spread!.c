#include<stdio.h>

main ()
{
    int n,a,b,x,y;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d%d",&a,&b);
        x=(a+b)/2;
        y=(a-b)/2;
        if ((a+b)%2==1||(a-b)%2==1)
        {
            printf("impossible\n");
            continue;
        }
        if (x>=0&&y>=0)
        {
            printf("%d %d\n",x,y);
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}
