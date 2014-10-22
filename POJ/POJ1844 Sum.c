#include<stdio.h>

int main(int argc, char* argv[])
{
	int s,i;
	for(scanf("%d",&s),s=-s,i=1;s<0||s%2;s+=i++);
	printf("%d\n",--i);
	return 0;
}
