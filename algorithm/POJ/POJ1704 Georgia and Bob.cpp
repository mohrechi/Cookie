#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	int t,n,k,pos[1005],dist[1005];
	cin>>t;
	pos[0] = 0;
	while(t--)
	{
	    cin>>n;
	    for(int i=1;i<=n;i++)
	    {
	        cin>>pos[i];
	    }
	    sort(pos+1, pos+n+1);
	    k = 0;
	    if(n&1)
	    {
	        for(int i=0;i<n;i+=2)
	        {
	            dist[k++] = pos[i+1] - pos[i] - 1;
	        }
	    }
	    else
	    {
	        for(int i=1;i<n;i+=2)
	        {
	            dist[k++] = pos[i+1] - pos[i] - 1;
	        }
	    }
	    for(int i=1;i<k;i++)
	    {
	        dist[0] ^= dist[i];
	    }
	    if(dist[0])
	    {
	        cout<<"Georgia will win"<<endl;
	    }
	    else
	    {
	        cout<<"Bob will win"<<endl;
	    }
	}
	return 0;
}
