#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int a[21],t,n;
	a[1]=3,a[2]=7;
	for(int i=3;i<=20;i++)
	{
	    a[i]=2*a[i-1]+a[i-2];
	}
	cin>>t;
	while(t--)
	{
	    cout<<(cin>>n,a[n])<<endl;
	}
	return 0;
}
