#include<stdio.h>

main()
{
    int t,n,a[105],b[105],i,j,k,min;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for (i=1;i<=n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            if (i==1)
            {
                min=a[i]*b[i];
                j=1;
            }
            else
            {
                k=a[i]*b[i];
                if (k<min)
                {
                    min=k;
                    j=i;
                }
            }
        }
        printf("%d\n",a[j]*b[j]);
    }
    return 0;
}
