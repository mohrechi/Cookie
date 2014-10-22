#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
	char s[50000];
	int i,t,l,b[50000];
	for(;;)
	{
	    scanf("%s",s);
	    if(*s==48) break;
	    l=strlen(s);
	    for(i=1,*b=1;i<l;i++)
        {
            t=s[i-1]*10+s[i]-528;
            if(s[i]==48)
            {
                if(i>1)b[i]=b[i-2];
                else b[i]=1;
                if(i>1)b[i-1]=b[i-2];
            }
            else if(t>26)b[i]=b[i-1];
            else if(t<10)b[i]=b[i-2];
            else
            {
                if(i>1)b[i]=b[i-1]+b[i-2];
                else b[i]=2;
            }
        }
	    printf("%d\n",b[i-1]);
	}
	return 0;
}
