#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	long long a[25],b[25];
	int t,n;
	a[0]=1,a[1]=1,a[2]=2;
	b[0]=0,b[1]=0,b[2]=1;
	for(int i=3;i<21;i++)
	{
	    a[i]=i*a[i-1];
	    b[i]=(i-1)*(b[i-1]+b[i-2]);
	}
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    printf("%.2lf%%\n",b[n]*100.0/a[n]);
	}
	return 0;
}
