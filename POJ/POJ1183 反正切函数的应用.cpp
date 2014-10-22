#include <stdio.h>
#include <cmath>

int main()
{
    __int64 a,b,c;
    while(scanf("%I64d",&a)!=EOF)
    {
         b=2*a;
         while((a*b+1)%(b-a)!=0) b--;
         c=(a*b+1)/(b-a);
         c=b+c;
         printf("%I64d\n",c);
    }
    return 0;
}
