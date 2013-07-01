#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
	    for(i=1;i<n;i++) if(i*(i+1)/2>=n) break;
	    if(i%2) printf("TERM %d IS %d/%d\n",n,i*(i+1)/2-n+1,n-i*(i-1)/2);
	    else printf("TERM %d IS %d/%d\n",n,n-i*(i-1)/2,i*(i+1)/2-n+1);
	}
	return 0;
}
