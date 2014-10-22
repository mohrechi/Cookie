#include<stdio.h>

int cmp(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}

int main(int argc, char* argv[])
{
	int m,n,a[20001],i,s;
	for(scanf("%d",&m);m--;)
	{
	    for(scanf("%d",&n),i=0;i<n;i++)scanf("%d",&a[i]);
	    qsort(a,n,sizeof(n),cmp);
	    for(i=2,s=0;i<n;i+=3) s+=a[i];
	    printf("%d\n",s);
	}
	return 0;
}
