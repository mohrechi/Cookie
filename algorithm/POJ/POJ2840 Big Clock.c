#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,a,b;
	scanf("%d",&n);
	while(n--)
	{
	    scanf("%d:%d",&a,&b);
	    if(b) printf("0\n");
	    else printf("%d\n",a>12?a-12:a+12);
	}
	return 0;
}
