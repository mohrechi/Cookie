#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int m,match[25];
	while(cin>>m)
	{
	    for(int i=0;i<m;i++)
	    {
	        cin>>match[i];
	    }
	    int result = match[0];
	    for(int i=1;i<m;i++)
	    {
	        result ^= match[i];
	    }
	    if(result)
	    {
	        cout<<"Yes"<<endl;
	    }
	    else
	    {
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}
