#include<stdio.h>

struct p
{
    int w;
    int a;
    int b;
}s[50001];

int cmp(const void* x, const void* y)
{
    return (*(struct p*)y).a-(*(struct p*)x).a;
}

int main(int argc, char* argv[])
{
	int n,k,i,j,m;
	for(scanf("%d%d",&n,&k),i=0;i<n;i++)
	{
	    scanf("%d%d",&s[i].a,&s[i].b);
	    s[i].w=i;
	}
	qsort(s,n,sizeof(*s),cmp);
	for(i=0,m=0;i<k;i++)if(s[i].b>m)m=s[i].b,j=i;
	printf("%d\n",s[j].w+1);
	return 0;
}
