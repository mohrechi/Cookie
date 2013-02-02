#include<stdio.h>

int main(int argc, char* argv[])
{
	int c,n,l,r,a,b;
	scanf("%d",&n);
	for(c=1;c<=n;c++)
	{
	    scanf("%d%d",&a,&b);
	    l=0,r=0;
	    while(a!=b)
	    {
	        if(a>b)
	        {
	            l+=a/b,a=a%b;
	            if(0==a) a=b,l--;
	        }
	        else
	        {
	            r+=b/a,b=b%a;
	            if(0==b) b=a,r--;
	        }
	    }
	    printf("Scenario #%d:\n%d %d\n\n",c,l,r);
	}
	return 0;
}
