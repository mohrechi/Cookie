#include <cstdio>
#include <cstring>
static const int MAXN = 1005;
double dp[MAXN][2];
bool p[MAXN][2];
double dfs(int n,int k)
{

    if(p[n][k]) return dp[n][k];
    double ans = 0.0;
    if(n==0)
    {
        return 0.0;
    }
    if(k==0)
    {
        ans = dfs(n,1)*(2.0/(n+2))+(dfs(n-1,0)+1)*(1.0*n/(n+2));
    }
    else
    {
        ans = (dfs(n-1,1)+1)*(1.0*n/(n+1));
    }
    p[n][k] = true;
    dp[n][k]=ans;
    return ans;

}
int main(int argc, char *argv[])
{
    int n;
    memset(p, false, sizeof(p));
    while(~scanf("%d",&n))
    {
        printf("%d\n", (int)(dfs(n, 0) + 0.5));
    }
    return 0;
}
