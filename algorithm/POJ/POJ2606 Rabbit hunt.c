#include<stdio.h>

int main(int argc, char* argv[])
{
	int i,j,k,n,t,m;
	float x[250],y[250];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%f%f",&x[i],&y[i]);
	for(i=0,m=0;i<n;i++)
	{
	    for(j=i+1;j<n;j++)
	    {
	        for(k=0,t=2;k<n;k++)
	        {
	            if(k!=i&&k!=j)
	            {
	                if((y[j]-y[i])/(x[j]-x[i])==(y[k]-y[i])/(x[k]-x[i])) t++;
	            }
	        }
	        if(t>m)m=t;
	    }
	}
	printf("%d\n",m);
	return 0;
}
