#include<stdio.h>

int main()
{
    int caseNum=0, r;
    double d,t,distance,mph,pi=3.1415927;
    while(scanf("%lf%d%lf",&d,&r,&t),r)
    {
        distance=pi*d*r/(5280*12);
        mph=3600*distance/t;
        printf("Trip #%d: %.2lf %.2lf\n",++caseNum,distance,mph);
    }
    return 0;
}
