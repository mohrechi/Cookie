#include<stdio.h>

main()
{
    int n,x,j,i,k,a[500000];
    while(1)
    {
        scanf("%d",&n);
        if (n==0)
        {
            break;
        }
        k=n*2;
        i=0;
        while(k--)
        {
            scanf("%d",&a[++i]);
            for(j=1;j<i;j++)
            {
                if (a[j]==a[i])
                {
                    a[j]=a[--i],i--;
                }
            }
        }
        if (i==0)
        {
            printf("Good\n");
        }
        else
        {
            printf("Bad\n");
        }
    }
    return 0;
}
