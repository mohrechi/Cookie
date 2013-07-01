#include<stdio.h>

int main()
{
    int n,time=1;
    float x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%f%f",&x,&y);
        printf("Property %d: This property will begin eroding in year %d.\n",time++,(int)(0.031415926*(x*x+y*y))+1);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
