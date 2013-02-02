#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int max,min,ans,i;
	char s[100];
	for(;;)
	{
	    scanf("%d",&i);
	    if(!i) break;
	    min=0,max=2100000000;
	    for(;;)
	    {
            gets(s);
            if(!strcmp(s,"too high"))
            {
                if(max>i) max=i;
            }
            if(!strcmp(s,"too low"))
            {
                if(min<i) min=i;
            }
            if(!strcmp(s,"right on")) break;
            scanf("%d",&i);
	    }
	    if(i>min&&i<max) printf("Stan may be honest\n");
	    else printf("Stan is dishonest\n");
	}
	return 0;
}
