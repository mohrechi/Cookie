#include<stdio.h>

int a[500000];
char c[5000000]={1};
int main(int argc, char* argv[])
{
	int i,j,t;
	*a=0;
	for(i=1;i<500000;i++)
	{
	    if(i>=a[i-1])a[i]=a[i-1]+i,c[a[i]]=1;
	    else
	    {
	        a[i]=a[i-1]-i;
	        if(c[a[i]]) a[i]+=2*i;
	        c[a[i]]=1;
	    }
	}
	for(;;)
	{
	    scanf("%d",&i);
	    if(-1==i) break;
	    printf("%d\n",a[i]);
	}
	return 0;
}
