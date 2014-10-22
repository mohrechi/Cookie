#include<stdio.h>
#include<math.h>

int stirling(int n)
{
	const double p=acos(-1.0);
	double c1=log10(2*p);
	double c2=0.434294481903;
	double c3=log10(1.0*n);
	int s=1;
	if(n>3)s=(c3+c1)/2+n*(c3-c2)+1;
	return s;
}

int main(int argc, char* argv[])
{
	int n,i;
	for(scanf("%d",&n);n--;)
	{
	    scanf("%d",&i);
	    printf("%d\n",stirling(i));
	}
	return 0;
}
