#include<stdio.h>

int main(int argc, char* argv[])
{
	int n;
	while(scanf("%d",&n),n)
	{
	    if(n%2) printf("%d\n",n-1);
	    else printf("No Solution!\n");
	}
	return 0;
}
