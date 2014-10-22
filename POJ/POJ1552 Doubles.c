#include<stdio.h>

int main(int argc, char* argv[])
{
	int a[200],b[25],i,j,n,s;
	for(;;)
	{
	    for(i=0;i<100;i++) a[i]=0;
	    scanf("%d",&n);
	    a[n]=1,j=1,s=0,b[0]=n;
	    if(-1==n) break;
	    for(;;)
	    {
	        scanf("%d",&n);
	        if(n==0) break;
	        b[j++]=n,a[n]=1;
	    }
	    for(i=0;i<j;i++) if(a[b[i]*2]==1) s++;
	    printf("%d\n",s);
	}
	return 0;
}
