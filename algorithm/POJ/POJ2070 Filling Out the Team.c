#include<stdio.h>

int main(void)
{
    float   sp;
    float   we;
    float   st;
    int     t;
    for(;;)
    {
        scanf("%f%f%f",&sp,&we,&st);
        if(0==we) break;
        t=0;
        if(sp<=4.5&&we>=150&&st>=200) printf("Wide Receiver "),t=1;
        if(sp<=6.0&&we>=300&&st>=500) printf("Lineman "),t=1;
        if(sp<=5.0&&we>=200&&st>=300) printf("Quarterback "),t=1;
        if(0==t) printf("No positions");
        printf("\n");
    }
    return 0;
}
