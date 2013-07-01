#include<stdio.h>

main ()
{
    int n,m;
    while((scanf("%d",&n))!=EOF)
    {
        while(n>=10)
        {
            m=0;
            while(n)
            {
                m+=n%10;
                n/=10;
            }
            n=m;
        }
        printf("%d\n",n);
    }
    return 0;
}
