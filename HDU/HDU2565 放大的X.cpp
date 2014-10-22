#include<stdio.h>
#include<memory.h>

int main(int argc, char *argv[])
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(i==j || i==n-j-1)
	            {
	                printf("X");
	            }
	            else if(j<i || j<n-i-1)
	            {
	                printf(" ");
	            }
	        }
	        printf("\n");
	    }
	    printf("\n");
	}
	return 0;
}
