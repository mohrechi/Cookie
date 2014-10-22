#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char a[100010],b;
	int i,n;
	while(scanf("%s",a)!=EOF)
	{
	    n=strlen(a);
	    for(i=0,scanf("%c",&b);b!=10;)
	    {
	        scanf("%c",&b);
	        if(a[i]==b) i++;
	    }
	    if(i==n) printf("Yes\n");
	    else printf("No\n");
	}
	return 0;
}
