#include<stdio.h>

int main(void)
{
	int t,n,i,j,a[100000],s;
	for(scanf("%d",&t);t--;)
	{
	    scanf("%d",&n);
	    for(i=1;i<=n;i++) scanf("%d",&a[i]);
	    for(i=1,s=0;i<=n;i++)
	    {
	        if(i!=a[i])
	        {
	            for(j=i+1;j<=n;j++)
	            {
	                if(a[j]==i)
	                {
	                    a[0]=a[i];
	                    a[i]=a[j];
	                    a[j]=a[0];
	                    s++;
	                }
	            }
	        }
	    }
	    printf("%d\n",s);
	}
	return 0;
}
