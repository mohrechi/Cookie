#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	long long dp[50][50];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<50;i++)
	{
	    dp[i][i]=1;
	}
	for(int i=1;i<50;i++)
	{
	    for(int j=i+1;j<50;j++)
	    {
	        dp[i][j]=dp[i][j-1]+dp[i][j-2];
	    }
	}
	int t,a,b;
	cin>>t;
	while(t--)
	{
	    cin>>a>>b;
	    cout<<dp[a][b]<<endl;
	}
	return 0;
}
