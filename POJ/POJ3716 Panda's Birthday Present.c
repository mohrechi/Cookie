#include<stdio.h>

int main(int argc, char* argv[])
{
	int m,n,t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&m,&n);
	    printf("%.3f\n",(m+n+10)/7.0);
	}
	return 0;
}
