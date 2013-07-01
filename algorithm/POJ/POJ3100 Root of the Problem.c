#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int m,n,i;
	double a,b;
	while(scanf("%d%d",&m,&n),m||n)
	{
	    for(i=1;;i++) if((b=pow(i,n))>=m) break;
	    a=m-pow(i-1,n),b=b-m;
	    printf("%d\n",a<b?i-1:i);
	}
	return 0;
}
