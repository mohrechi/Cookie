#include<stdio.h>

int cmp(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}

int main(int argc, char* argv[])
{
	int i,j,k,m,n,t,a[1005],s;
	for(scanf("%d",&t),i=1;i<=t;i++)
	{
	    for(scanf("%d%d",&m,&n),j=0;j<n;scanf("%d",&a[j++]));
	    qsort(a,n,sizeof(int),cmp);
	    for(j=0,s=0;j<n;j++)
	    {
	        s+=a[j];
	        if(s>=m)break;
	    }
	    if(j<n) printf("Scenario #%d:\n%d\n\n",i,j+1);
	    else printf("Scenario #%d:\nimpossible\n\n",i);
	}
	return 0;
}
