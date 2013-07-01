#include<stdio.h>
#include<string.h>

int main(void)
{
	int n,a,b,c,t,maxm,minm;
	char name[20],max[20],min[20];
	for(;;)
	{
	    scanf("%d",&n);
	    if(-1==n) break;
	    maxm=0,minm=300;
	    while(n--)
	    {
	        scanf("%d%d%d%s",&a,&b,&c,name);
	        t=a*b*c;
	        if(t>maxm)
	        {
	            maxm=t;
	            strcpy(max,name);
	        }
	        if(t<minm)
	        {
	            minm=t;
	            strcpy(min,name);
	        }
	    }
	    printf("%s took clay from %s.\n",max,min);
	}
	return 0;
}
