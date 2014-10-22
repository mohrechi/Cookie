#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    double n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&n);
        n=pow(3.0,n);
        printf("%.0lf\n",n);
    }
    return 0;
}
