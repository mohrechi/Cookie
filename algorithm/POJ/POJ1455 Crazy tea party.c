#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,t,t1,t2;
	for(scanf("%d",&n);n--;)
	{
	    scanf("%d",&t);
	    if(t%2==0)
	    {
	        t1=t/2;
	        t1=t1*(t1-1);
	    }
	    else
	    {
	        t1=t/2+1;
	        t2=t-t1;
	        t1=t1*(t1-1)/2;
	        t2=t2*(t2-1)/2;
	        t1+=t2;
	    }
        printf("%d\n",t1);
	}
	return 0;
}
