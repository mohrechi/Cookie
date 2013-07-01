#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char s[1000][15];
	int i,j,k,n,f,t=0;
	while(scanf("%s",s[0])!=EOF)
	{
	    t++,n=1;
	    while(scanf("%s",s[n]),*s[n++]!='9');
	    for(i=0,f=1;i<n;i++)
	    {
	        for(j=i+1;j<n;j++)
	        {
	            k=strlen(s[i])<strlen(s[j])?strlen(s[i]):strlen(s[j]);
	            if(!strncmp(s[i],s[j],k))
	            {
	                f=0;
	                break;
	            }
	        }
	    }
	    if(f) printf("Set %d is immediately decodable\n",t);
	    else printf("Set %d is not immediately decodable\n",t);
	}
	return 0;
}
