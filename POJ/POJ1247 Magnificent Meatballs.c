#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,s[35],a,b,i,j;
	for(;;)
	{
	    scanf("%d",&n);
	    if(!n) break;
	    for(i=0;i<n;i++) scanf("%d",&s[i]);
	    i=0;j=n-1,a=0,b=0;
        while(i<=j)
        {
            if(a>b)b+=s[j--];
            else a+=s[i++];
        }
	    if(a==b) printf("Sam stops at position %d and Ella stops at position %d.\n",j+1,i+1);
	    else printf("No equal partitioning.\n");
	}
	return 0;
}
