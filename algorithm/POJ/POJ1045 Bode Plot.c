#include <stdio.h>
#include <math.h>

int main(void)
{
    int     i;
    int     n;
    float   VR;
    float   VS;
    float   R;
    float   C;
    float   w;
    scanf("%f%f%f%d",&VS,&R,&C,&n);
    while(n--)
    {
        scanf("%f",&w);
        VR=C*R*w*VS/sqrt(1+C*C*R*R*w*w);
        printf("%.3f\n",VR);
    }
    return 0;
}
