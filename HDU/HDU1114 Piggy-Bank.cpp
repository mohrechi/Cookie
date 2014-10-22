#include <iostream>
#include <cmath>
using namespace std;
const int inf=1000000000;

int main(int argc, char *argv[])
{
	int t,e,f,n,maxWeight,value[505],weight[505],dp[10005];
	cin>>t;
	while(t--)
	{
	    cin>>e>>f>>n;
	    maxWeight=f-e;
	    for(int i=0;i<n;i++)
	    {
	        cin>>value[i]>>weight[i];
	    }
	    for(int i=0;i<=maxWeight;i++)
	    {
	        dp[i]=inf;
	    }
	    dp[0]=0;
	    for(int i=0;i<=maxWeight;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(i+weight[j]<=maxWeight)
	            {
	                dp[i+weight[j]]=min(dp[i+weight[j]], dp[i]+value[j]);
	            }
	        }
	    }
	    if(dp[maxWeight]==inf)
	    {
	        cout<<"This is impossible."<<endl;
	    }
	    else
	    {
	        cout<<"The minimum amount of money in the piggy-bank is "<<dp[maxWeight]<<"."<<endl;
	    }
	}
	return 0;
}
