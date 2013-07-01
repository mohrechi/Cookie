#include<stdio.h>

int main(int argc, char* argv[])
{
	long i,j,k,n;
	while(scanf("%ld",&k)!=EOF)
	{
		i=1,j=1,n=1;
		while(j<k)
		{
			j=j*10+1;
			++n;
		}
		while(j%k!=0)
		{
			j=j%k*10+1;
			++n;
		}
		printf("%d\n",n);
	}
	return 0;
}
