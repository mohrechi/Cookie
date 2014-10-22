#include<stdio.h>

int main(int argc, char* argv[])
{
	char a[30050];
	int s,e,n,i,c=0;
	for(scanf("%d",&n),i=0;i<n;i++)scanf("%s",a+i);
	s=0,e=n-1;
	while(s!=e)
	{
	    if(a[s]==a[e])
	    {
	        i=1;
	        while(a[s+i]==a[e-i])
	        {
	            if(e-s-2*i<=1) break;
	            i++;
	        }
	        if(a[s+i]<=a[e-i])
	        {
	            printf("%c",a[s++]);
	            c++;
	            if(c%80==0)printf("\n");
	        }
	        else
	        {
	            printf("%c",a[e--]);
	            c++;
	            if(c%80==0)printf("\n");
	        }
	    }
	    else if(a[s]<a[e])
	    {
	        printf("%c",a[s++]);
            c++;
            if(c%80==0)printf("\n");
	    }
	    else
	    {
	        printf("%c",a[e--]);
            c++;
            if(c%80==0)printf("\n");
	    }
	}
	printf("%c\n",a[s]);
	return 0;
}
