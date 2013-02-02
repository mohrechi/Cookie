#include<stdio.h>

int main(int argc, char* argv[])
{
	int a[100005],i,n;
	while(scanf("%d",&n),n)
	{
	    for(i=1;i<=n;i++) scanf("%d",&a[i]);
	    for(i=1;i<=n;i++) if(a[a[i]]!=i) break;
	    if(i==n+1) printf("ambiguous\n");
	    else printf("not ambiguous\n");
	}
	return 0;
}
