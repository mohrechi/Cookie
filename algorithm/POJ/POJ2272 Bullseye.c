#include<stdio.h>
#include<math.h>

int f(double a, double b)
{
    a=a*a+b*b;
	if(a<=9)return 100;
	else if(a<=36)return 80;
    else if(a<=81)return 60;
    else if(a<=144)return 40;
    else if(a<=225)return 20;
    return 0;
}

int main(int argc, char* argv[])
{
	int k,a,b;
	double i,j;
	for(;;)
	{
	    scanf("%lf%lf",&i,&j);
	    if(i==-100) break;
	    a=0,k=2;
	    a+=f(i,j);
	    while(k--)
	    {
	        scanf("%lf%lf",&i,&j);
	        a+=f(i,j);
	    }
	    b=0,k=3;
	    while(k--)
	    {
	        scanf("%lf%lf",&i,&j);
	        b+=f(i,j);
	    }
	    printf("SCORE: %d to %d, ",a,b);
	    if(a>b) printf("PLAYER 1 WINS.\n");
	    else if(a<b) printf("PLAYER 2 WINS.\n");
	    else printf("TIE.\n");
	}
	return 0;
}
