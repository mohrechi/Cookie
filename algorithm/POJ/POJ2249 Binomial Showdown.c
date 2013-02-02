#include<stdio.h>

int main(int argc, char* argv[])
{
	int i,j,s;
	double k;
	for(;;)
	{
	    scanf("%d%d",&i,&j);
	    if(!i&&!j) break;
	    if(j>i/2)j=i-j;
	    k=1;
	    while(j)
	    {
	        k*=i--;
	        k/=j--;
	    }
	    printf("%.0f\n",k);
	}
	return 0;
}
