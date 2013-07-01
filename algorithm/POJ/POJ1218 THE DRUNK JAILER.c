#include<stdio.h>

int main(int argc, char* argv[])
{
	int     i,j,n;
	scanf("%d",&i);
	while(i--)
	{
	    scanf("%d",&n);
	    for(j=1;j*j<=n;j++);
	    printf("%d\n",j-1);
	}
	return 0;
}
