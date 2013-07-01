#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int n,a,i,j,s;
	for(scanf("%d",&n),i=0;i<n;i++)
	{
	    scanf("%d",&a);
	    for(j=0;;j++)
	    {
	        if(a<10) break;
	        if(a%10>4) a=a/10+1;
	        else a/=10;
	    }
	    printf("%d",a);
	    while(j--)printf("0");
	    printf("\n");
	}
	return 0;
}
