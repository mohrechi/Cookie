#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    int n,i;
	__int64 a,b;
	for(scanf("%d",&n),i=1;i<=n;i++)
	{
	    scanf("%I64d%I64d",&a,&b);
	    printf("Scenario #%d:\n%I64d\n\n",i,(a+b)*(b-a+1)/2);
	}
	return 0;
}
