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
        printf("(x ");
        if(x>=0) printf("-");
        else printf("+");
        printf(" %.3f)^2 + (y ",fabs(x));
        if(y>=0) printf("-");
        else printf("+");
        printf(" %.3f)^2 = %.3f^2\n",fabs(y),fabs(r));
        printf("x^2 + y^2 ");
        if(x<0) printf("+");
        else printf("-");
        printf(" %.3fx ",fabs(x*2));
        if(y<0) printf("+");
        else printf("-");
        printf(" %.3fy ",fabs(y*2));
        if(x*2,y*2,x*x+y*y-r*r>0) printf("+");
        else printf("-");
        printf(" %.3f = 0\n\n",fabs(x*x+y*y-r*r));
    }
    return 0;
}
