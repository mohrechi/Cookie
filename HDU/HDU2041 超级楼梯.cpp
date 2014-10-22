#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int a[45];
	a[1]=0,a[2]=1,a[3]=2;
	for(int i=4;i<=40;i++)
	{
	    a[i]=a[i-1]+a[i-2];
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
