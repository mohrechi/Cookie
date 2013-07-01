#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n,m;
    int c[21],g[21],dp[21][15001];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&g[i]);
    }
    dp[0][7500]=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=-7500;j<=7500;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(j-c[k]*g[i]>=-7500 && j-c[k]*g[i]<=7500)
                {
                    dp[i][j+7500] += dp[i-1][j-c[k]*g[i]+7500];
                }
            }
        }
    }
    printf("%d\n",dp[m][7500]);
    return 0;
}
