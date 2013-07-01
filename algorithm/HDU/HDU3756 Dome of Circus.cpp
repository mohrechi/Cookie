#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

struct Point
{
    double x,y;
    void get(double a, double b, double c)
    {
        x = sqrt(a*a+b*b);
        y = c;
    }
    void input()
    {
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        get(a,b,c);
    }
}point[10005];

int t,n;

double getRadius(double h)
{
    double r=0.0;
    for(int i=0;i<n;i++)
    {
        r=max(r,h*point[i].x/(h-point[i].y));
    }
    return r;
}

double getMinHeight()
{
    double h=0.0;
    for(int i=0;i<n;i++)
    {
        h=max(h,point[i].y);
    }
    return h;
}

int main(int argc, char *argv[])
{
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	    {
	        point[i].input();
	    }
	    double h,r,l,r1,r2,m1,m2,v;
	    v=1e100,l=getMinHeight(),r=5000;
	    while(r-l>1e-4)
	    {
	        m1=(l*2+r)/3;
	        m2=(l+r*2)/3;
	        r1=getRadius(m1);
	        r2=getRadius(m2);
	        if(r1*r1*m1>r2*r2*m2)
	        {
	            l=m1;
	        }
	        else
	        {
	            r=m2;
	        }
	    }
	    printf("%.3lf %.3lf\n",m1,r1);
	}
	return 0;
}
