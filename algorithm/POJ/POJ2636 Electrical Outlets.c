#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,i,a,s,t;
	for(scanf("%d",&n);n--;)
	{
	    for(scanf("%d",&t),i=0,s=0;i<t;i++)
	    {
	        scanf("%d",&a);
	        s+=a;
	    }
	    printf("%d\n",s+1-t);
	}
	return 0;
}
