#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int m,n,i,j;
	char s[300];
	for(;;)
	{
	    scanf("%d",&m);
	    if(!m) break;
	    scanf("%s",s);
	    n=strlen(s);
	    n/=m;
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if (j%2)printf("%c",s[(m-i-1)+j*m]);
	            else printf("%c",s[i+j*m]);
	        }
	    }
	    printf("\n");
	}
	return 0;
}
