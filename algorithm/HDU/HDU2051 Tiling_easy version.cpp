#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	long long a[35];
	a[1]=1,a[2]=3;
	for(int i=3;i<=30;i++)
	{
	    a[i]=a[i-1]+2*a[i-2];
	}
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    cout<<a[n]<<endl;
	}
	return 0;
}
