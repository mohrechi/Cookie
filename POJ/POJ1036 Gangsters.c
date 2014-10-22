#include<stdio.h>
#include<math.h>

struct gan
{
    int t;
    int p;
    int s;
}g[105];

int cmp(const void *a ,const void *b)
{
    return (*(struct gan *)a).t>(*(struct gan *)b).t?1:-1;
}

int main(int argc, char* argv[])
{
	int n,k,t,i,j,m,a[105];
	scanf("%d%d%d",&n,&k,&t);
	for(i=0;i<n;i++) scanf("%d",&g[i].t);
	for(i=0;i<n;i++) scanf("%d",&g[i].p);
	for(i=0;i<n;i++)
	{
	    scanf("%d",&g[i].s);
	    a[i]=-1;
	}
	qsort(g,n,sizeof(g[0]),cmp);
	for(i=0;i<n;i++)
	{
	    if(g[i].t<g[i].s) continue;
	    a[i]=0;
	    for(j=0;j<i;j++)
	    {
            if(a[j]>a[i]&&g[i].t-g[j].t>=abs(g[i].s-g[j].s)) a[i]=a[j];
	    }
        if(a[i]>=0) a[i]+=g[i].p;
	}
	for(i=0,m=0;i<n;i++)
	{
	    if(a[i]>m) m=a[i];
	}
	printf("%d\n",m);
	return 0;
}
