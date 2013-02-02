#include<stdio.h>

int a[105][105];
int f(int i, int j)
{
    int n=0;
    if(a[i][j])
    {
        a[i][j]=0;
        n+=f(i-1,j);
        n+=f(i+1,j);
        n+=f(i,j-1);
        n+=f(i,j+1);
        return n+1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char* argv[])
{
	int n,m,k,i,j,t;
	for(i=0;i<105;i++)for(j=0;j<105;j++) a[i][j]=0;
	for(scanf("%d%d%d",&n,&m,&k);k--;)
	{
	    scanf("%d%d",&i,&j);
	    a[i][j]=1;
	}
	for(i=1,k=0;i<=n;i++)
	{
	    for(j=1;j<=m;j++)
	    {
	        t=f(i,j);
	        if(t>k)k=t;
	    }
	}
	printf("%d\n",k);
	return 0;
}
