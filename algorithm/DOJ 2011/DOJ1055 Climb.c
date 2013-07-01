#include<stdio.h>
#include<math.h>

main ()
{
    float h,h1,a1,v1,h2,a2,v2,t1,t2;
    int n=10;
    for (;n;n--)
    {
        scanf("%f%f%f%f%f%f%f",&h,&h1,&a1,&v1,&h2,&a2,&v2);
        if (a1==0.0)
        {
            t1=(h-h1)/v1;
        }
        else
        {
            t1=(0.0-v1+sqrt(v1*v1-4.0*a1*0.5*(h1-h)))/a1;
        }
        if (a2==0.0)
        {
            t2=(h-h2)/v2;
        }
        {
            t2=(0.0-v2+sqrt(v2*v2-4.0*a2*0.5*(h2-h)))/a2;
        }
        if (t1>t2)
        {
            printf("Monkey two win!\n");
        }
        else if (t1<t2)
        {
            printf("Monkey one win!\n");
        }
        else
        {
            printf("Square!\n");
        }
    }
    return 0;
}
