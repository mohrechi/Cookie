#include<stdio.h>

int a[1000005]={0,1,2};
int main(int argc, char* argv[])
{
	int i,n;
	scanf("%d",&n);
	for(i=3;i<=n;i++)
	{
	    if(i%2) a[i]=a[i-1];
	    else
	    {
	        a[i]=a[i-2]+a[i/2];
	        a[i]%=1000000000;
	    }
	}
	printf("%d\n",a[n]);
	return 0;
}
