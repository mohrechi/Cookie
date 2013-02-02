#include<stdio.h>
#include<math.h>

int main()
{
    int t,n;
    double sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=1.0;
        for(int i=1;i<=n;i++)
        {
            sum+=log10((double)i);
        }
        printf("%d\n",(int)sum);
    }
    return 0;
}
