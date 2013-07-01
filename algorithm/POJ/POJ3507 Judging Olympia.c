#include<stdio.h>

int main(int argc, char* argv[])
{
    int a[6],temp,i,max,min;
    while(1)
    {
        max=0;
        min=2000000000;
        for(i=0;i<6;i++)
        {
            scanf("%d",&a[i]);
            if(max<a[i])max=a[i];
            if(min>a[i])min=a[i];
        }
        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0)break;
        printf("%g\n",(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]-max-min)/(float)4);
    }
    return 0;
}
