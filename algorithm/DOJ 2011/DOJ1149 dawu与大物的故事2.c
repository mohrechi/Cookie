#include<stdio.h>

main ()
{
    int i,j,t,a[110],*p,t3;
    while (scanf("%d",&t)!=EOF)
    {
        for(i=1;i<=t;i++)
        {
            scanf("%d",&a[i]);
        }
        t3=t/2+1;
        for(j=1;j<=t3;j++)
        {
            p=&a[1];
            for(i=2;i<=t;i++)
            {
                if (a[i]>*p)
                {
                    p=&a[i];
                }
            }
            if (j==t3)
            {
                printf("%d\n",*p);
            }
            else
            {
                *p=0;
            }
        }
    }
    return 0;
}

