#include<stdio.h>

int main(int argc, char* argv[])
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	    printf("%d %d %d\n",-3*b+3*c+a,-8*b+6*c+3*a,-15*b+10*c+6*a);
	return 0;
}
