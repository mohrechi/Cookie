#include<stdio.h>

main()
{
    int n,s,t;
    while(scanf("%d",&n)!=EOF)
    {
        s=n*(n+1)/2;
        while(--n)
        {
            scanf("%d",&t);
            s-=t;
        }
        printf("%d\n",s);
    }
    return 0;
}
