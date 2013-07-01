#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,a,b,c,m,i=1;
	for(scanf("%d",&m);m--;)
	{
	    scanf("%d",&n);
	    a=n/25,n%=25;
	    b=n/10,n%=10;
	    c=n/5,n%=5;
	    printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",i++,a,b,c,n);
	}
	return 0;
}
