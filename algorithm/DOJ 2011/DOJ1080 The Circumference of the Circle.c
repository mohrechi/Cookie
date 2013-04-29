#include<stdio.h>
#include<math.h>

main ()
{
    float x1,y1,x2,y2,x3,y3,x,y,r;
    while(scanf("%f%f%f%f%f%f",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
    {
        x=((y3-y2)/2+(x1-x3)*(x1+x3)/2/(y1-y3)-(x1-x2)*(x1+x2)/2/(y1-y2))/((x1-x3)/(y1-y3)-(x1-x2)/(y1-y2));
        y=((x3-x2)/2+(y1-y3)*(y1+y3)/2/(x1-x3)-(y1-y2)*(y1+y2)/2/(x1-x2))/((y1-y3)/(x1-x3)-(y1-y2)/(x1-x2));
        if (x1==x2)y=(y1+y2)/2;
        if (x1==x3)y=(y1+y3)/2;
        if (y1==y2)x=(x1+x2)/2;
        if (y1==y3)x=(x1+x3)/2;
        r=sqrt(pow(x-x1,2)+pow(y-y1,2));
        printf("%.2f\n",2.0*3.141592653589793*r);
    }
    return 0;
}
