#include<stdio.h>

int main(int argc, char* argv[])
{
	int i,a;
	char s[256];
	for(;;)
	{
	    gets(s+1);
	    if(s[1]=='#')break;
	    i=0,a=0;
	    while(s[++i])
	        if(s[i]!=' ')a+=(s[i]-'@')*i;
	    printf("%d\n",a);
	}
	return 0;
}
