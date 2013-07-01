#include<stdio.h>

long a[10000005];
int main(int argc, char* argv[])
{
	int i,j,k,n;
	j=k=1,a[1]=1;
	for(i=2;i<=10000000;i++)
	{
	    if(a[j]*2==a[k]*3)a[i++]=a[j++]*2+1,k++;
	    if(a[j]*2<a[k]*3)a[i]=a[j++]*2+1;
	    else a[i]=a[k++]*3+1;
	}
	while(scanf("%ld",&n)!=EOF) printf("%d\n",a[n]);
	return 0;
}
