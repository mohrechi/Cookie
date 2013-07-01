#include <iostream>
#include <cstring>
using namespace std;

int dp[100001][11];
int max(int a, int b)
{
    return a>b?a:b;
}

int max(int a, int b, int c)
{
    return max(max(a,b),c);
}

int main(int argc, char *argv[])
{
	int n,x,y,m;
	while(cin>>n,n)
	{
	    memset(dp,0,sizeof(dp));
	    m=0;
	    while(n--)
	    {
	        cin>>x>>y;
	        dp[y][x]++;
	        m=max(m,y);
	    }
	    for(int i=m-1;i>=0;i--)
	    {
	        for(int j=0;j<=10;j++)
	        {
	            if(j==0)
	            {
	                dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
	            }
	            else if(j==10)
	            {
	                dp[i][j]+=max(dp[i+1][j],dp[i+1][j-1]);
	            }
	            else
	            {
	                dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1],dp[i+1][j-1]);
	            }
	        }
	    }
	    cout<<dp[0][5]<<endl;
	}
	return 0;
}
