#include<stdio.h>

int main(void)
{
	int a,i,s;
	printf("PERFECTION OUTPUT\n");
	for(;;)
	{
	    scanf("%d",&a);
	    if(!a) break;
	    for(i=1,s=0;i<a;i++)
	    {
	        if(a%i==0) s+=i;
	    }
	    printf("%5d  ",a);
	    if(a==s) printf("PERFECT\n");
	    if(a>s) printf("DEFICIENT\n");
	    if(a<s) printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
