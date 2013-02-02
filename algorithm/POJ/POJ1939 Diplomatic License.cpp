#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	double x[1000],y[1000];
	while(scanf("%d",&n)!=EOF)
	{
	    for(int i=0;i<n;i++)
	    {
	        scanf("%lf%lf",&x[i],&y[i]);
	    }
	    printf("%d",n);
	    for(int i=1;i<n;i++)
	    {
	        printf(" %.6lf %.6lf",(x[i]+x[i-1])/2,(y[i]+y[i-1])/2);
	    }
	    printf(" %.6lf %.6lf\n",(x[0]+x[n-1])/2,(y[0]+y[n-1])/2);
	}
	return 0;
}
