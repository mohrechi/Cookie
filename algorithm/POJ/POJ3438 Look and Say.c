#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,i;
	char s[1005],*t;
	for(scanf("%d",&n);n--;)
	{
	    scanf("%s",s);
	    t=s;
	    while(*t)
	    {
	        i=1;
	        while(*t==*(t+1)) t++,i++;
	        printf("%d%c",i,*t);
	        t++;
	    }
	    printf("\n");
	}
	return 0;
}
