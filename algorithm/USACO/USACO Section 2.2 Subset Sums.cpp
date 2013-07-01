/*
ID: cyberzh1
LANG: C++
TASK: subset
*/
#include<stdio.h>
FILE* fin=fopen("subset.in","r");
FILE* fout=fopen("subset.out","w");
int main()
{
    unsigned int n,dp[40][400]={0},sum;
    fscanf(fin,"%d",&n);
    sum=(n*(n+1))>>1;
    if(sum&1)
    {
        fprintf(fout,"0\n");
        return 0;
    }
    dp[1][0]=dp[1][1]=1;
    sum>>=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j-i>0) dp[i][j]=dp[i-1][j]+dp[i-1][j-i];
            else dp[i][j]=dp[i-1][j];
        }
    }
    fprintf(fout,"%d\n",dp[n][sum]);
    return 0;
}
