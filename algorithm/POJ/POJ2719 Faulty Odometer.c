#include<stdio.h>
#include<string.h>
#include<math.h>

int main(int argc, char* argv[])
{
	char s[20];
	int n,i,j,k;
	while(scanf("%s",s),*s!=48)
	{
	    j=strlen(s);
	    k=pow(9,j-1);
	    for(i=0,n=0;i<j;i++)
	    {
	        if(s[i]<=51) n+=(s[i]-48)*k;
	        else n+=(s[i]-49)*k;
	        k/=9;
	    }
	    printf("%s: %d\n",s,n);
	}
	return 0;
}
