#include<stdio.h>

main()
{
    int n,i,k,j;
    char s[100];
    while(scanf("%d",&n)!=EOF)
    {
        i=0;
        while(n)
        {
            s[i++]=n%2;
            n/=2;
        }
        for(j=0;j<i/2;j++)
        {
            k=s[j],s[j]=s[i-j-1],s[i-j-1]=k;
        }
        s[i]=2,i=0;
        while(s[i]<2)
        {
            printf("%d",s[i++]);
        }
        printf("\n");
    }
    return 0;
}
