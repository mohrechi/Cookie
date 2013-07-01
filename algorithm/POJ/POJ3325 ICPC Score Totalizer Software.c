#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,m,a,s,max,min;
	while(scanf("%d",&m),m)
	{
	    n=m,max=0,min=2100000000,s=0;
	    while(n--)
	    {
	        scanf("%d",&a);
	        s+=a;
	        if(a>max) max=a;
	        if(a<min) min=a;
	    }
	    printf("%d\n",(s-max-min)/(m-2));
	}
	return 0;
}
