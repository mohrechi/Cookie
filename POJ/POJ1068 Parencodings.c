#include<stdio.h>

int main(int argc, char* argv[])
{
	int     t;
	int     n;
	int     i;
	int     j;
	int     temp2;
	int     num[41];
	int     temp[81];
	int*    p;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(i=0;i<n;i++) scanf("%d",&num[i]);
	    temp2=n*2;
	    for(i=0;i<temp2;i++) temp[i]=0;
	    j=num[0], p=&temp[j], *p++=1;
	    for(i=1;i<n;i++)
	    {
	        while(num[i]>j)
	        {
	            if(!*p) j++;
	            p++;
	        }
	        *p++=1;
	    }
	    j=num[0];
	    while(n--)
	    {
	        p=&temp[j-1], i=0;
	        while(*p)
	        {
	            if(*p==1) i++;
	            p--;
	        }
	        *p=2;
	        if(n)
                printf("%d ",i+1);
            else
                printf("%d\n",i+1);
	        j++;
	        while(!temp[j]) j++;
	    }
	}
	return 0;
}
