#include<stdio.h>

int main(int argc, char* argv[])
{
	int m,n,s;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
	    s=m;
	    while(m>=n)
	    {
	        s+=m/n;
	        m-=m/n*(n-1);
	    }
	    printf("%d\n",s);
	}
	return 0;
}
