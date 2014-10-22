#include<stdio.h>

int main(int argc, char* argv[])
{
    int a,b,c,n;
	scanf("%d",&n);
	while(n--)
	{
	    scanf("%d%d%d",&a,&b,&c);
	    if(b-a>c) printf("advertise\n");
	    else if(b-a==c) printf("does not matter\n");
	    else printf("do not advertise\n");
	}
	return 0;
}
