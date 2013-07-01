#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int dp[105][1005];

int main(int argc, char *argv[])
{
	int t,n,m,l,length[105],value[105];
	cin>>t;
	while(t--)
	{
	    cin>>n>>m>>l;
	    for(int i=0;i<n;i++)
	    {
	        cin>>length[i]>>value[i];
	    }
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<=l;i++)
	    {
	        dp[0][i]=0;
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=m;j>=1;j--)
	        {
	            for(int k=l;k>=length[i];k--)
	            {
	                if(dp[j-1][k-length[i]]>=0)
	                {
	                    dp[j][k]=max(dp[j][k], dp[j-1][k-length[i]]+value[i]);
	                }
	            }
	        }
	    }
	    if(dp[m][l]<0)
	    {
	        cout<<0<<endl;
	    }
	    else
	    {
	        cout<<dp[m][l]<<endl;
	    }
	}
	return 0;
}
