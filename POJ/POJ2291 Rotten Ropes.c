#include<stdio.h>

int cmp(const void *a, const void *b)
{
    return *(int*)b-*(int*)a;
}

int main(int argc, char* argv[])
{
	int a[2000],t,i,j,k,s,m;
	for(scanf("%d",&t);t--;)
	{
	    scanf("%d",&k);
	    for(i=0;i<k;i++) scanf("%d",&a[i]);
	    m=0;
	    qsort(a,k,sizeof(*a),cmp);
	    while(k)
	    {
	        s=2100000000;
	        for(i=0;i<k;i++)
	        {
	            if(s>a[i])s=a[i];
	        }
	        s*=k--;
	        if(s>m) m=s;
	    }
	    printf("%d\n",m);
	}
	return 0;
}
