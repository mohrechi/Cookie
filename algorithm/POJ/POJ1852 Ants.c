#include<stdio.h>

int main(int argc, char* argv[])
{
	int t,m,n,i,j,min,max,s;
	for(scanf("%d",&t);t--;)
	{
	    min=0,max=0;
	    for(scanf("%d%d",&m,&n),i=0;i<n;i++)
	    {
	        scanf("%d",&j);
	        s=j>m-j?j:m-j;
	        max=max>s?max:s;
	        s=(j<m-j?j:m-j);
	        min=min<s?s:min;
	    }
	    printf("%d %d\n",min,max);
	}
	return 0;
}
