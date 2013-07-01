#include<stdio.h>

int main()
{
    float sum,temp;
    int i;
    sum=0;
    for(i=1;i<=12;i++)
    {
        scanf("%f",&temp);
        sum+=temp;
    }
    sum/=12;
    printf("$%.2f\n",sum);
    return 0;
}
