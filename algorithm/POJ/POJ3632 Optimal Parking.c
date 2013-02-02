#include<stdio.h>

int main(int argc, char* argv[])
{
	int m,n,t,max,min;
	for(scanf("%d",&m);m--;)
	{
	    max=0,min=2100000000;
	    for(scanf("%d",&n);n--;)
	    {
	        scanf("%d",&t);
	        if(t>max)max=t;
	        if(t<min)min=t;
	    }
	    printf("%d\n",(max-min)*2);
	}
	return 0;
}
