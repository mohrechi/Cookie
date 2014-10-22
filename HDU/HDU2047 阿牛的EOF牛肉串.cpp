#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	long long a[40],n;
	a[1]=3,a[2]=8;
	for(int i=3;i<40;i++)
	{
	    a[i]=2*(a[i-1]+a[i-2]);
	}
	while(cin>>n)
	{
	    cout<<a[n]<<endl;
	}
	return 0;
}
