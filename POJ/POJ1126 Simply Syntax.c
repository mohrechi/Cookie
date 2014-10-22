#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char s[300];
	int i,j,n,f;
	while(scanf("%s",s)!=EOF)
	{
	    n=strlen(s);
	    for(i=n-1,f=1,j=0;i>=0;i--)
	    {
	        if(s[i]>='p'&&s[i]<='z')j++;
	        else if(s[i]=='C'||s[i]=='D'||s[i]=='E'||s[i]=='I')j--;
	        else if(s[i]=='N'){}
	        else f=0;
	    }
	    if(j!=1)f=0;
	    if(f) printf("YES\n");
	    else printf("NO\n");
	}
	return 0;
}
