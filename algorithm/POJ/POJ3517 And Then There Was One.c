#include<stdio.h>

int n,k,m;
int f(int i)
{
	if(i==1) return 0;
	return (k+f(i-1))%i;
}

int main(int argc, char* argv[])
{
	while(scanf("%d%d%d",&n,&k,&m),n||k||m)
	{
	    printf("%d\n",(f(n-1)+m)%n+1);
	}
	return 0;
}
