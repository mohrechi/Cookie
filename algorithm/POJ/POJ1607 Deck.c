#include<stdio.h>

int main(void)
{
	int i,n,k;
	double s;
	printf("Cards  Overhang \n");
	while(scanf("%d",&n)!=EOF)
	{
	    for(i=0,k=2,s=0;i<n;i++)
	    {
	        s+=1.0/k;
	        k+=2;
	    }
	    printf("%5d%10.3f \n",n,s);
	}
	return 0;
}
