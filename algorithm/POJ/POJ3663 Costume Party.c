#include<stdio.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int main(int argc, char* argv[])
{
	int n,m,a[20005],i,j,s;
	for(scanf("%d%d",&n,&m),i=0;i<n;i++)scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	for(i=0,s=0;i<n&&a[i]<m;i++)
	{
	    for(j=i+1;j<n&&a[i]+a[j]<=m;j++)s++;
	}
	printf("%d\n",s);
	return 0;
}
