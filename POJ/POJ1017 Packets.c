#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,a,b,c,d,e,f,x,y,u[4]={0,5,3,1};
	for(;;)
	{
	    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	    if(!a&&!b&&!c&&!d&&!e&&!f) break;
	    n=f+e+d+(c+3)/4;
	    y=5*d+u[c%4];
	    if(b>y) n+=(b-y+8)/9;
	    x=36*n-36*f-25*e-16*d-9*c-4*b;
	    if(a>x)n+=(a-x+35)/36;
	    printf("%d\n",n);
	}
	return 0;
}
