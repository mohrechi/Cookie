#include<stdio.h>

int cmp(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}

int main(int argc, char* argv[])
{
	int m,n,a[20005],i,s;
	for(scanf("%d%d",&m,&n),i=0;i<m;i++) scanf("%d",&a[i]);
	qsort(a,m,sizeof(int),cmp);
	for(i=0,s=0;i<m;i++)
	{
	    s+=a[i];
	    if(s>=n)break;
	}
	if(i!=m)i++;
	printf("%d\n",i);
	return 0;
}
