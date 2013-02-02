#include<stdio.h>

int main(int argc, char* argv[])
{
	int a,i,j,k,m,n,t;
	scanf("%d",&n);
	for(i=0,m=0;i<n;i++)
	{
	    for(j=0,a=0;j<n;j++)
	    {
	        scanf("%d",&t);
	        if(t>2)a++;
	    }
	    if(a>m)m=a,k=i+1;
	}
	printf("%d\n",k);
	return 0;
}
