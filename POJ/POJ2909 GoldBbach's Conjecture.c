#include<stdio.h>

int s[1000000]={0};
int main(int argc, char* argv[])
{
	int n,i,k,t,f,c;
	for(i=2;i<500000;i++)
	{
	    for(k=2;(t=k*i)<1000000;k++) s[t]=1;
	}
	for(;;)
	{
	    scanf("%d",&n);
	    if(0==n)break;
	    t=n/2;
	    for(i=3,c=0;i<=t;i+=2)
	    {
	        if(s[i])continue;
	        if(!s[n-i])c++;
	    }
	    printf("%d\n",c);
	}
	return 0;
}
