#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int i,j,k,n,a[3005];
	while(scanf("%d",&n)!=EOF)
	{
	    for(i=0;i<n;i++) a[i]=0;
	    scanf("%d",&j);
	    for(i=1;i<n;i++)
	    {
	        scanf("%d",&k);
	        a[abs(j-k)]=1;
	        j=k;
	    }
	    for(i=1;i<n;i++)
	    {
	        if(!a[i]) break;
	    }
	    if(i==n) printf("Jolly\n");
	    else printf("Not jolly\n");
	}
	return 0;
}
