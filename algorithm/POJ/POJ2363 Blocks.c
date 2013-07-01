#include<stdio.h>

int main(int argc, char* argv[])
{
	int t,i,j,k,n,s,e,m;
	for(scanf("%d",&t);t--;)
	{
	    scanf("%d",&n);
	    for(i=1,m=2100000000;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            e=i*j;
	            if(e>n) break;
	            if(n%e==0)
	            {
	                k=n/e;
	                s=i*j+j*k+k*i;
	                if(s<m) m=s;
	            }
	        }
	    }
	    printf("%d\n",m*2);
	}
	return 0;
}
