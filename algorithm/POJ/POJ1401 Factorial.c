#include<stdio.h>

int main(int argc, char* argv[])
{
	int t,n,s=0;
	for(scanf("%d",&t);t--;s=0)
	{
	    scanf("%d",&n);
	    while(n>=5)
	    {
	        s+=n/5;
	        n/=5;
	    }
	    printf("%d\n",s);
	}
	return 0;
}
