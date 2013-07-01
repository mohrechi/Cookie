#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	double m,n;
	while(scanf("%lf%lf",&m,&n)!=EOF)
	printf("%.0f\n",pow(n,1/m));
	return 0;
}
