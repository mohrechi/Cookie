#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int n,e,i,t,a=0,b=0;
	scanf("%d%d",&n,&e);
	while(--n)scanf("%d",&t),a+=t;
	while(--e)scanf("%d",&t),b+=t;
	printf("%.0f\n",ceil(sqrt(a*a+b*b)));
	return 0;
}
