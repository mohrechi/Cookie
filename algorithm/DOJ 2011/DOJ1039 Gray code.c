#include<stdio.h>
#include<math.h>

main ()
{
    long a[1005]={0},i,j,k,n,n2;
    char c[1005]={0};
    while(1)
    {
        scanf("%d",&n);
        if (n==0)
        {
            break;
        }
        n2=(int)pow(2,n);
        for (i=1;i<=n;i++)
        {
            a[i]=(int)pow(2,n-i);
            c[i]=0;
        }
        for (j=1;j<=n2;j++)
        {
            for (i=1;i<=n;i++)
            {
                if (a[i]>=pow(2,n-i+1))
                {
                    a[i]=0;
                    if (c[i]>0)
                    {
                        c[i]=0;
                    }
                    else
                    {
                        c[i]=1;
                    }
                }
                a[i]++;
            }
            for (k=1;k<=n;k++)
            {
                printf("%d",c[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
