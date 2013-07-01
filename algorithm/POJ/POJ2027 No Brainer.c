#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
	    scanf("%d%d",&a,&b);
	    if(a>=b) printf("MMM BRAINS\n");
	    else printf("NO BRAINS\n");
	}
	return 0;
}
