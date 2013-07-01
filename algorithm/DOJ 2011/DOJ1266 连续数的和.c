#include<stdio.h>

main()
{
    int n,i,j,k,s;
    scanf("%d",&n);
    k=0;
    for(i=1;i<=n;i++)
    {
        s=0;
        for(j=i;j<=n;j++)
        {
            s+=j;
            if(s==n)
            {
                k++;
            }
            if(s>n)
            {
                break;
            }
        }
    }
    printf("%d",k);
    return 0;
}
