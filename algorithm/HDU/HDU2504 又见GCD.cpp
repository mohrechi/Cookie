#include<stdio.h>
#include<stdlib.h>
int gcd(int p, int q)
{
    if(q==0) return p;
    return gcd(q,p%q);
}
int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        c=2*b;
        while(gcd(a,c)!=b)
        {
            c+=b;
        }
        printf("%d\n",c);
    }
    return 0;
}
