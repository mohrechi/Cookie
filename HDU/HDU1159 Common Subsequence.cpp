#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	int dp[500][500];
	char s1[500],s2[500];
	int l1,l2;
	while(cin>>s1+1>>s2+1)
	{
	    l1=strlen(s1+1);
	    l2=strlen(s2+1);
	    memset(dp,0,sizeof(dp));
	    for(int i=1;i<=l1;i++)
	    {
	        for(int j=1;j<=l2;j++)
	        {
	            if(s1[i]==s2[j])
	            {
	                dp[i][j]=dp[i-1][j-1]+1;
	            }
	            else
	            {
	                if(dp[i][j-1]>dp[i-1][j])
	                {
	                    dp[i][j]=dp[i][j-1];
	                }
	                else
	                {
	                    dp[i][j]=dp[i-1][j];
	                }
	            }
	        }
	    }
	    cout<<dp[l1][l2]<<endl;
	}
	return 0;
}
