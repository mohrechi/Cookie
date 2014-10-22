#include<stdio.h>

int main(int argc, char* argv[])
{
	int t,n,i,j,s,c=1,a[1100];
	for(scanf("%d",&t);c<=t;c++)
	{
	    for(scanf("%d",&n),i=0;i<n;i++) scanf("%d",&a[i]);
	    for(i=0,s=0;i<n;i++)
	    {
	        for(j=n-1;j>i;j--)
	        {
	            if(a[j]<a[j-1])
	            {
	                a[j]+=a[j-1];
	                a[j-1]=a[j]-a[j-1];
	                a[j]-=a[j-1];
	                s++;
	            }
	        }
	    }
	    printf ("Scenario #%d:\n%d\n\n",c,s);
	}
	return 0;
}
