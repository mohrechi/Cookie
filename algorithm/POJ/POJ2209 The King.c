#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int n,t,s=0,i;
	scanf("%d%d",&n,&t);
	while(n--)
	{
	    scanf("%d",&i);
	    i=(int)pow(i,t);
	    s+=i>0?i:0;
	}
	printf("%d\n",s);
	return 0;
}
