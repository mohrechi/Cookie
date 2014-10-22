#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAXN 105
#define inf 1000000000

char s[MAXN];
int dp[MAXN][MAXN];
int prev[MAXN][MAXN];

void output(int i, int j)
{
    if(i > j)
    {
        return;
    }
    if(i==j)
    {
        if(s[i] == '[' || s[i] == ']')
        {
            printf("[]");
        }
        else
        {
            printf("()");
        }
    }
    else if(prev[i][j] == -1)
    {
        printf("%c",s[i]);
        output(i+1,j-1);
        printf("%c",s[j]);
    }
    else
    {
        output(i, prev[i][j]);
        output(prev[i][j]+1, j);
    }
}

int main(int argc, char *argv[])
{
	while(gets(s))
	{
	    int len=strlen(s);
	    for(int i=0;i<len;i++)
	    {
	        dp[i][i] = 1;
	    }
	    for(int st=1;st<len;st++)
	    {
	        for(int i=0;i+st<len;i++)
	        {
	            int j=i+st;
	            dp[i][j] = inf;
	            if((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
	            {
	                if(dp[i][j] > dp[i+1][j-1])
	                {
	                    dp[i][j] = dp[i+1][j-1];
	                    prev[i][j] = -1;
	                }
	            }
	            for(int k=i;k<j;k++)
	            {
	                if(dp[i][j] > dp[i][k] + dp[k+1][j])
	                {
	                    dp[i][j] = dp[i][k] + dp[k+1][j];
	                    prev[i][j] = k;
	                }
	            }
	        }
	    }
	    output(0,len-1);
	    printf("\n");
	}
	return 0;
}
