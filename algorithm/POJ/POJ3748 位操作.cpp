#include<stdio.h>

int main(int argc, char* argv[])
{
	int r,x,y;
	scanf("%x,%d,%d",&r,&x,&y);
	r&=~(1<<x);
	r|=1<<y--;
	r|=1<<y--;
	r&=~(1<<y);
	printf("%x\n",r);
	return 0;
}
