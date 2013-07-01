#include<stdio.h>

int cmp( const void *a , const void *b )
{
    return *(int *)a - *(int *)b;
}

int main(int argc, char* argv[])
{
	int n,i,j,a[10000];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	printf("%d\n",a[n/2]);
	return 0;
}
