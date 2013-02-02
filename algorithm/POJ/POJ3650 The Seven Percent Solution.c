#include<stdio.h>

int main(int argc, char* argv[])
{
	char s[100],*p;
	while(gets(s),*s!='#')
	{
	    p=s;
	    while(*p)
	    {
	        switch (*p)
	        {
	            case ' ':printf("%%20");break;
	            case '!':printf("%%21");break;
	            case '$':printf("%%24");break;
	            case '%':printf("%%25");break;
	            case '(':printf("%%28");break;
	            case ')':printf("%%29");break;
	            case '*':printf("%%2a");break;
	            default: printf("%c",*p);
	        }
	        p++;
	    }
	    printf("\n");
	}
	return 0;
}
