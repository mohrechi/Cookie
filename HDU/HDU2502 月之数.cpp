#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int a[25],b[25],t,n;
	a[1]=0,a[2]=1;
	b[1]=1,b[2]=3;
	for(int i=3;i<21;i++)
	{
	    a[i]=a[i-1]*2;
	    b[i]=a[i]+2*b[i-1];
	}
	cin>>t;
	while(t--)
	{
	    cout<<(cin>>n,b[n])<<endl;
	}
	return 0;
}
