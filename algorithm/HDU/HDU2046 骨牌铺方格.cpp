#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	long long a[55],n;
	a[1]=1,a[2]=2,a[3]=3;
	for(int i=4;i<=50;i++)
	{
	    a[i]=a[i-1]+a[i-2];
	}
	while(cin>>n)
	{
	    cout<<a[n]<<endl;
	}
	return 0;
}
