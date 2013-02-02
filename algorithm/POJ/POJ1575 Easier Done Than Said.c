#include<stdio.h>
#include<string.h>

int j(char c)
{
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
    else if(c==0) return -1;
    return 0;
}

int main(int argc, char* argv[])
{
	char s[30];
	int i,n,f;
	while(scanf("%s",s),strcmp(s,"end"))
	{
	    for(i=0,n=0,f=0;s[i];i++)
	    {
	        if(j(s[i]))n++;
	        if(s[i+1]==s[i]&&s[i]!='e'&&s[i]!='o') f=1;
	        if(j(s[i])==j(s[i+1])&&j(s[i])==j(s[i+2])) f=1;
	    }
	    if(f||!n) printf("<%s> is not acceptable.\n",s);
	    else printf("<%s> is acceptable.\n",s);
	}
	return 0;
}
