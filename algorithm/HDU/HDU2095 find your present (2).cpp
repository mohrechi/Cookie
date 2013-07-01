#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,num,ans;
    while(scanf("%d",&n),n)
    {
        ans=0;
        while(n--)
        {
            scanf("%d",&num);
            ans^=num;
        }
        printf("%d\n",ans);
    }
    return 0;
}
