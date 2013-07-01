#include<stdio.h>

int main(int argc, char* argv[])
{
	int a,b,c,d;
	for(;;)
	{
	    scanf("%d%d%d%d",&a,&b,&c,&d);
	    if(0==a) break;
	    if(a>b) a+=b,b=a-b,a-=b;
	    if(c>d)c+=d,d=c-d,c-=d;
	    if(c*b/a>=d) printf("%d%%\n",d*100/b>100?100:d*100/b);
	    else printf("%d%%\n",c*100/a>100?100:c*100/a);
	}
	return 0;
}
