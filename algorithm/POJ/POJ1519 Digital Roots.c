#include<stdio.h>

int main(int argc, char* argv[])
{
	int s,t,a,i;
	char n[1000];
	for(;;)
	{
	    scanf("%s",n);
	    if(*n=='0') break;
	    i=0,a=0;
	    while(n[i])a+=n[i++]-'0';
	    while(a>9)
	    {
	        t=a,s=0;
	        while(t>9)
	        {
	            s+=t%10;
	            t/=10;
	        }
	        a=t+s;
	    }
	    printf("%d\n",a);
	}
	return 0;
}
