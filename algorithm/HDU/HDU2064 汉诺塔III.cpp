#include<stdio.h>

int main()
{
    int n;
    __int64 ans;
    while(scanf("%d",&n)!=EOF)
    {
        ans=1;
        while(n--)
        {
            ans*=3;
        }
        ans--;
        printf("%I64d\n",ans);
    }
    return 0;
}
