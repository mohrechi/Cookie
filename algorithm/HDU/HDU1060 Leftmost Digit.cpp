#include<stdio.h>
#include<math.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double a,c;
        long long b,d;
        a=n*log10((double)n);
        b=(long long)a;
        c=a-b;
        d=(long long)pow(10,c);
        printf("%lld\n",d);
    }
    return 0;
}
