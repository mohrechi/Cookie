#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    int fib[30];
    fib[0]=0,fib[1]=1;
    for(int i=2;i<21;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n<21) {printf("%d\n",fib[n]);continue;}
        double tmp=n*log10((1+sqrt(5.0))*0.5) - 0.5*log10(5.0);
        double p=tmp-(int)tmp;
        double num=pow(10.0,p);
        while(num<1000) num*=10;
        printf("%d\n",(int)num);
    }
    return 0;
}
