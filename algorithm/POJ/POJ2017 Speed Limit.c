#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,a,b1,b2,sum;
	for(;;)
	{
	    scanf("%d",&n);
	    if(-1==n)break;
	    b1=0,sum=0;
	    while(n--)
	    {
	        scanf("%d%d",&a,&b2);
	        sum+=a*(b2-b1);
	        b1=b2;
	    }
	    printf("%d miles\n",sum);
	}
	return 0;
}
