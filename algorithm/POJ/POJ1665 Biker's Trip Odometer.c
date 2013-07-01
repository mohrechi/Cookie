#include<stdio.h>

int main(void)
{
	float a,c,r,s;
	int t=1,b;
	while(scanf("%f%d%f",&a,&b,&c)!=EOF)
	{
	    if(!b)break;
	    r=3.1415927*a*b/5280.0/12.0;
	    s=r/c*3600.0;
	    printf("Trip #%d: %.2f %.2f\n",t++,r,s);
	}
	return 0;
}
