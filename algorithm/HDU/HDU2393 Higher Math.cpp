#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a*=a, b*=b, c*=c;
        printf("Scenario #%d:\n",i);
        if(a==b+c||b==a+c||c==a+b)
        {
            printf("yes");
        }
        else
        {
            printf("no");
        }
        printf("\n\n");
    }
    return 0;
}
