#include<stdio.h>

int main(int argc, char* argv[])
{
	int n,x1,y1,x2,y2,x3,y3,x4,y4;
	float t;
	printf("INTERSECTING LINES OUTPUT\n");
	scanf("%d",&n);
	while(n--)
	{
	    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		x1-=x2;y1-=y2,x3-=x4,y3-=y4;
		t=x1*y3-y1*x3;
		if(!t)
		{
			x2-=x4;y2-=y4;
			puts(x2*y3==x3*y2?"LINE":"NONE");
		}
		else
		{
			printf("POINT %.2f %.2f\n",(x1*y2*x3-y1*x2*x3+x1*y3*x4-x1*x3*y4)/t,(x1*y2*y3-y1*x2*y3+y1*y3*x4-y1*x3*y4)/t);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
