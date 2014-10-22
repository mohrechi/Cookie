#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
	int t,n,maxVolume,value[1005],volume[1005];
	int dp[1005];
	cin>>t;
	while(t--)
	{
	    cin>>n>>maxVolume;
	    for(int i=0;i<n;i++)
	    {
	        cin>>value[i];
	    }
	    for(int i=0;i<n;i++)
	    {
	        cin>>volume[i];
	    }
	    memset(dp,0,sizeof(dp));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=maxVolume;j>=volume[i];j--)
	        {
	            dp[j]=max(dp[j],dp[j-volume[i]]+value[i]);
	        }
	    }
	    cout<<dp[maxVolume]<<endl;
	}
	return 0;
}
