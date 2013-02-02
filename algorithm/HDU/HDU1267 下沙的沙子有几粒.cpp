#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    long long dp[21][21];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<21;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<21;i++)
    {
        for(int j=i;j<21;j++)
        {
            dp[j][i]=dp[j][i-1]+dp[j-1][i];
        }
    }
    int m,n;
    while(cin>>m>>n)
    {
        cout<<dp[m][n]<<endl;
    }
	return 0;
}
