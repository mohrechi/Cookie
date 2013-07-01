#include<stdio.h>

int main(int argc, char* agrv[])
{
    int     i;
    int     j;
    int     n;
    int     sum;
    for(;;)
    {
        scanf("%d",&n);
        if(0==n) break;
        for(i=1;;i++) if(i*(i+1)/2>n) break;
        printf("%d ",n);
        sum=0;
        for(j=1;j<i;j++) sum+=j*j;
        n-=i*(i-1)/2, sum+=n*i;
        printf("%d\n",sum);
    }
    return 0;
}
