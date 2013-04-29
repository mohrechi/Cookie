#include<stdio.h>

main()
{
    int m,n,s,i;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(m=1;;)
        {
            s=1;
            for(i=2;i<=n-1;i++)
            s=(s+m-1)%i+1;
            if(s==1)break;
            m++;
        }
        printf("%d\n",m);
    }
    return 0;
}
