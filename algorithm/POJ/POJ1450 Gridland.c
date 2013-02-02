#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,a,b,i;
	float s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    scanf("%d%d",&a,&b);
	    if(a*b%2==0) s=a*b;
	    else s=a*b+0.41;
	    printf("Scenario #%d:\n%.2f\n\n",i,s);
	}
	return 0;
}
