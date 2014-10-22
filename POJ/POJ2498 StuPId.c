#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	int t,i,j,k,b[3]={9,7,3},c,d,e;
	char s[10],*p;
	for(scanf("%d",&t),d=1;d<=t;d++)
	{
	    scanf("%s",s);
	    if (strlen(s)==7)
	    {
            for(i=0,c=0,p=s;*p;i++,p++)
            {
                if(*p=='?') k=i,e=b[i%3];
                else c+=(*p-48)*b[i%3];
            }
	    }
	    else
	    {
	        for(i=0,c=0,p=s;*p;i++,p++)
            {
                if(*p=='?') k=i,e=b[(i+1)%3];
                else c+=(*p-48)*b[(i+1)%3];
            }
	    }
	    for(i=0;i<10;i++)
	    {
	        if((c+e*i)%10==0) break;
	    }
	    s[k]=i+48;
	    printf("Scenario #%d:\n%s\n\n",d,s);
	}
	return 0;
}
