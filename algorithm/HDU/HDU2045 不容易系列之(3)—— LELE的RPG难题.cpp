#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	long long a[55],b[55],n;
	a[1]=1,a[2]=2;
    b[1]=b[2]=0;
    for(int i=3;i<=50;i++)
    {
        a[i]=a[i-1]+b[i-1]*2;
        b[i]=a[i-1];
    }
	while(cin>>n)
	{
	    cout<<3*a[n]<<endl;
	}
	return 0;
}
