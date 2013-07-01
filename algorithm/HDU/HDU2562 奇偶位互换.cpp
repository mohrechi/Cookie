#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	char s[50];
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>s;
	    for(int i=0;s[i];i+=2)
	    {
	        s[i]^=s[i+1];
	        s[i+1]^=s[i];
	        s[i]^=s[i+1];
	    }
	    cout<<s<<endl;
	}
	return 0;
}
