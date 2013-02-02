#include<stdio.h>

int main(int argc, char* argv[])
{
	int i,m;
	__int64 n;
	for(scanf("%d",&m),i=1;i<=m;i++)
	{
	    scanf("%I64d",&n);
	    printf("%d %I64d %I64d\n",i,n,n*(n+1)/2*(n+2)*(n+3)/4);
	}
	return 0;
}
