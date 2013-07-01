#include<stdio.h>

int main(int argc, char* argv[])
{
	int a,b,f,m,n,i,t;
	while(scanf("%d",&n),n)
	{
	    for(i=1,f=0,m=0;i<=n;i++)
	    {
	        scanf("%d%d",&a,&b);
	        a+=b;
	        if(a>8)
	        {
	            f=1;
	            if(a>m) m=a,t=i;
	        }
	    }
	    if(f) printf("%d\n",t);
	    else printf("0\n");
	}
	return 0;
}
