#include<stdio.h>

int main(void)
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
	    for(i=1,j=1;i<=n;i++)
	    {
            j*=i;
            while(!(j%10)) j/=10;
            j%=100000;
	    }
	    printf("%5d -> %d\n",n,j%10);
	}
	return 0;
}
