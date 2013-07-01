#include<stdio.h>

void swap(double *a, double *b)
{
    double t;
    t=*a,*a=*b,*b=t;
    return;
}

int main(int argc, char* argv[])
{
    double ax,ay,bx,by,cx,cy,dx,dy;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy)!=EOF)
    {
        if(cx==ax&&cy==ay)
        {
            swap(&ax,&bx);
            swap(&ay,&by);
        }
        else if(dx==bx&&dy==by)
        {
            swap(&cx,&dx);
            swap(&cy,&dy);
        }
        else if(dx==ax&&dy==ay)
        {
            swap(&ax,&bx);
            swap(&ay,&by);
            swap(&cx,&dx);
            swap(&cy,&dy);
        }
        printf("%.3lf %.3lf\n",ax-bx+dx,ay-by+dy);
    }
    return 0;
}
