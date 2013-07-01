#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int t,n,i,j,f;
	for(scanf("%d",&t);t--;)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	    {
	        if ((n-(int)pow(2,i))%(int)pow(2,i+1)==0)
	        break;
	    }
	    j=(int)pow(2,i)-1;
	    printf("%d %d\n",n-j,n+j);
	}
	return 0;
}
