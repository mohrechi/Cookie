#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        a*=a, b*=b, c*=c;
        if(a==b+c||b==a+c||c==a+b)
        {
            printf("good\n");
        }
        else if(a==b||b==c||c==a)
        {
            printf("perfect\n");
        }
        else
        {
            printf("just a triangle\n");
        }
    }
    return 0;
}
