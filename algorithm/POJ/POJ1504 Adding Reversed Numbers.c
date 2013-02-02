#include<stdio.h>

int f(int n)
{
    int s=0;
    while(n)
    {
        s=s*10+n%10;
        n/=10;
    }
    return s;
}

int main()
{
    int n,a,b;
    for(scanf("%d",&n);n--;)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",f(f(a)+f(b)));
    }
    return 0;
}
