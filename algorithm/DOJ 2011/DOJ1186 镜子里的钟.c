#include<stdio.h>

int main()
{
    int hh,mm;
    while(scanf("%d:%d",&hh,&mm)!=EOF)
    {
        if(hh==0&&mm==0)
        {
            printf("00:00\n");
            continue;
        }
        hh=12-hh;
        if(mm>0) hh--,mm=60-mm;
        if(hh<10)printf("0");
        printf("%d:",hh);
        if(mm<10)printf("0");
        printf("%d\n",mm);
    }
    return 0;
}
