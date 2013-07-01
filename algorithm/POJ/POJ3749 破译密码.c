#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char s[300],*p;
	for(;;)
	{
	    gets(s);
	    if(*s==69) break;
	    gets(s);
	    p=s;
	    while(*p)
	    {
	        if(*p>='F'&&*p<='Z') *p=*p-5;
	        else if(*p>='A'&&*p<='E') *p=*p+21;
	        p++;
	    }
	    printf("%s\n",s);
	    gets(s);
	}
	return 0;
}
