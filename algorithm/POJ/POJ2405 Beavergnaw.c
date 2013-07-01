#include<stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	double D,d,v;
	while(scanf("%lf%lf",&D,&v))
	{
	    if(!D&&!v) break;
	    d=pow(D*D*D-6*v/3.1415926,1.0/3);
		printf("%.3lf\n",d);
	}
	return 0;
}
