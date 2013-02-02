#include<stdio.h>

int main()
{
    float length,sum;
    int num;
    while(1)
    {
        scanf("%f",&length);
        if(0==length) break;
        num=2,sum=0.5;
        while(sum<length)
        {
            num++, sum+=(float)1/num;
        }
        printf("%d card(s)\n",num-1);
    }
    return 0;
}
