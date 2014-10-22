#include<stdio.h>

int main(int argc, char* argv[])
{
	int i;
	while(scanf("%d",&i)!=EOF)
	{
	    if(i%2) printf("%d\n\n",(i+1)/2*i);
	    else printf("%d\n\n",i/2*(i+1));
	}
	return 0;
}
