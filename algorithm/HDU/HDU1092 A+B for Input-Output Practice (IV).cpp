#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,a,b;
    while(scanf("%d",&n),n)
    {
        b=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            b+=a;
        }
        printf("%d\n",b);
    }
    return 0;
}
