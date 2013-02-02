#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	double x[110],y[110],r,s;
	int n,i;
	scanf("%d%lf",&n,&r);
	for(i=0;i<n;i++)
	{
	    scanf("%lf%lf",&x[i],&y[i]);
	}
	s=sqrt(pow((x[0]-x[n-1]),2)+pow((y[0]-y[n-1]),2));
	for(i=1;i<n;i++)
	{
	    s+=sqrt(pow((x[i]-x[i-1]),2)+pow((y[i]-y[i-1]),2));
	}
	s+=3.14159265358979*r*2;
	printf("%.2lf\n",s);
	return 0;
}
