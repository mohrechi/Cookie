#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 105
#define INF 0x7FFFFFFF

int main(int argc, char *argv[])
{
	int n, num[MAXN], dp[MAXN][MAXN];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&num[i]);
	}
	--n;
    for(int i=1;i<=n;i++)
    {
        dp[i][i] = 0;
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i+l-1<=n;i++)
        {
            int j=i+l-1;
            dp[i][j] = INF;
            for(int k=i;k<j;k++)
            {
                int temp = dp[i][k] + dp[k+1][j] + num[i-1]*num[k]*num[j];
                if(temp<dp[i][j])
                {
                    dp[i][j] = temp;
                }
            }
        }
    }
    printf("%d\n",dp[1][n]);
	return 0;
}
