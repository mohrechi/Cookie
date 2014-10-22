#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

double const PI = acos(-1.0);

int main(int argc, char *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
	    double bottom,up,left,right,height,volumn,mid;
	    cin>>bottom>>up>>height>>volumn;
	    left=0, right=height;
	    while(right-left>1e-8)
	    {
	        mid=(left+right)*0.5;
	        double tempr=mid/height*(up-bottom)+bottom;
	        double temp=PI*(bottom*bottom+bottom*tempr+tempr*tempr)*mid/3;
	        if(temp<volumn)
	        {
	            left=mid;
	        }
	        else
	        {
	            right=mid;
	        }
	    }
	    printf("%.6lf\n",mid);
	}
	return 0;
}
