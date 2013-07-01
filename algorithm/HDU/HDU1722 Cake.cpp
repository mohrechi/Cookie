#include<stdio.h>
#include<stdlib.h>
int gcd(int p, int q)
{
    if(q==0) return p;
    return gcd(q,p%q);
}

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        printf("%d\n",a+b-gcd(a,b));
    }
    return 0;
}
