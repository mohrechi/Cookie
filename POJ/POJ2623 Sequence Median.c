#include<stdio.h>

int cmp(const void* a, const void* b)
{
    return *(unsigned int*)a-*(unsigned int*)b;
}

int main(int argc, char* argv[])
{
	unsigned int a[250000],i,j,n;
	for(scanf("%d",&n),i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	if (n%2) printf("%.1f\n",(float)a[n/2]);
	else printf("%.1f\n",a[n/2]/2.0+a[n/2-1]/2.0);
	return 0;
}
