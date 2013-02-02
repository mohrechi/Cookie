#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main(int argc, char *argv[])
{
	int a[105][105],n,m,dp[105];
	while(cin>>n>>m,n||m)
	{
	    for(int i=0;i<n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    memset(dp,0,sizeof(dp));
	    for(int k=0;k<n;k++)
	    {
	        for(int i=m;i>=0;i--)
	        {
	            for(int j=1;j<=m;j++)
	            {
	                if(i>=j)
	                {
	                    dp[i]=max(dp[i],dp[i-j]+a[k][j]);
	                }
	            }
	        }
	    }
	    cout<<dp[m]<<endl;
	}
	return 0;
}
