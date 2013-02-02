#include<stdio.h>

int main()
{
    __int64 n,k,t,i;
    while(scanf("%I64d%I64d",&n,&t)!=EOF)
    {
        if(n==0&&t==0)break;
        for(i=1;i<=n;i++)
        {
            k=t%2;
            if(k==1)
            {
                printf("%I64d\n",i);
                break;
            }
            else t=t/2;
        }
    }
    return 0;
}
