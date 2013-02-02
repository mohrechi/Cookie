#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define PI 3.1415926535897
#define side_limit 100

double angle(double x1,double y1,double x2,double y2)
{
    double a=atan2(y1,x1),b=atan2(y2,x2);
    if (a-b>PI) a-=2*PI;
    if (a-b<-PI) a+=2*PI;
    return a-b;
}

int main(void)
{
    int i,side_n;
    double k,h,sum_angle,find_max,find_min,x[side_limit+10],y[side_limit+10];
    scanf("%lf%lf%d",&k,&h,&side_n);
    for (i=1;i<=side_n;i++) scanf("%lf%lf",&x[i],&y[i]);
    x[0]=x[side_n],y[0]=y[side_n];
    sum_angle=0,find_max=find_min=0;
    for (i=1;i<=side_n;i++)
    {
        sum_angle+=angle(x[i],y[i],x[i-1],y[i-1]);

        find_max=max(find_max,sum_angle),find_min=min(find_min,sum_angle);
    }
    printf("%.2f\n",min(find_max-find_min,2*PI)*k*h);
    return 0;
}
