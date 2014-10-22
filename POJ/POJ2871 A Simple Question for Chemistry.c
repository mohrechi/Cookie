#include<stdio.h>

int main(int argc, char* argv[])
{
    float a,b;
    for(scanf("%f",&a);;a=b)
    {
        scanf("%f",&b);
        if(b==999)break;
        printf("%.2f\n",b-a);
    }
    printf("End of Output\n");
    return 0;
}
