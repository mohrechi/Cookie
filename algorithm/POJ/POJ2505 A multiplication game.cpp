#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
	long long n;
	while(cin>>n)
	{
	    if(n<=9)
	    {
	        cout<<"Stan wins."<<endl;
	    }
	    else
	    {
	        while(n>9)
	        {
	            n=(long long)ceil((double)n/18);
	        }
	        if(n<=1)
	        {
	            cout<<"Ollie wins."<<endl;
	        }
	        else
	        {
	            cout<<"Stan wins."<<endl;
	        }
	    }
	}
	return 0;
}
