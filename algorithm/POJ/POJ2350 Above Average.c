#include<stdio.h>

int main(int argc, char* argv[])
{
	int a[1005],i,j,k,t;
	double s;
	for(scanf("%d",&t);t--;)
	{
	    scanf("%d",&j);
	    for(i=0,s=0;i<j;i++)
	    {
	        scanf("%d",&a[i]);
	        s+=a[i];
	    }
	    s/=j;
	    for(i=0,k=0;i<j;i++)
	    {
	        if(s<a[i]) k++;
	    }
	    printf("%.3f%%\n",100.0*k/j);
	}
	return 0;
}
