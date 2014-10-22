#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int n,x,y,z,m;
	char a[9],b[9],c[9],temp[9];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s %s %s",a,b,c);
		m=1;
		while(++m<17)
		{
			x=strtol(a,NULL,m);
			y=strtol(b,NULL,m);
			z=strtol(c,NULL,m);
			if(x*y!=z)continue;
			if(strcmp(a,itoa(x,temp,m)))continue;
			if(strcmp(b,itoa(y,temp,m)))continue;
			if(strcmp(c,itoa(z,temp,m)))continue;
			break;
		}
		printf("%d\n",m<17?m:0);
	}
	return 0;
}
