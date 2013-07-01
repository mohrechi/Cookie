#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    cout<<(cin>>n, (1<<n)-1)<<endl;
	}
	return 0;
}
