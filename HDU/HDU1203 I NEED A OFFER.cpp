#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	int n,m,weight[1005];
	double value[1005],ans,dp[10005];
	while(cin>>m>>n,n||m)
	{
	    for(int i=0;i<n;i++)
	    {
	        cin>>weight[i]>>value[i];
	    }
	    for(int i=0;i<=m;i++)
	    {
	        dp[i]=1.0;
	    }
	    for(int i=0;i<n;i++)
	    {
	        for(int j=m;j>=weight[i];j--)
	        {
	            dp[j]=min(dp[j],dp[j-weight[i]]*(1-value[i]));
	        }
	    }
        printf("%.1lf%%\n",(1-dp[m])*100);
	}
	return 0;
}
