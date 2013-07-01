#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[])
{
	int r,m,y;
	double s;
	scanf("%d%d%d",&r,&m,&y);
	s=r/100.0+1;
	s=pow(s,y);
	printf("%d",(int)(s*m));
	return 0;
}
