#include<stdio.h>

int main(int argc, char* argv[])
{
	char s[30][30],n,i,j=1;
	for(;;)
	{
	    scanf("%d",&n);
	    if(0==n)break;
	    for(i=0;i<n;i++) scanf("%s",s[i]);
	    printf("SET %d\n",j++);
	    for(i=0;i<n;i+=2)printf("%s\n",s[i]);
	    for(i=n-n%2-1;i>0;i-=2)printf("%s\n",s[i]);
	}
	return 0;
}
