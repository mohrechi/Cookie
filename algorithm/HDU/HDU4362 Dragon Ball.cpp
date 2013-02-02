#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1100;
const int MAXM = 60;
const int INF = 0x7fffffff;

int m, n, s;
struct Data
{
    int x, w;
    bool operator < (const Data &data) const
    {
        return x < data.x;
    }
}data[MAXM][MAXN];
int dp[MAXM][MAXN];
int ans;

void solve()
{
    for(int i=0;i<m;++i)
    {
        sort(data[i], data[i] + n);
        for(int j=0;j<n;++j)
        {
            dp[i][j] = INF;
        }
    }
    for(int i=0;i<n;++i)
    {
        dp[0][i] = abs(s - data[0][i].x) + data[0][i].w;
    }
    for(int i=1;i<m;++i)
    {
        int mini = INF;
        for(int j=0,k=0;k<n;)
        {
            if(data[i-1][j].x > data[i][k].x)
            {
                if(++ k < n)
                {
                    if(mini != INF)
                    {
                        mini += abs(data[i][k].x - data[i][k-1].x);
                        dp[i][k] = min(dp[i][k], mini);
                    }
                }
            }
            else
            {
                mini = min(mini, abs(data[i][k].x - data[i-1][j].x) + dp[i-1][j]);
                dp[i][k] = min(dp[i][k], mini);
                if(j < n - 1)
                {
                    ++ j;
                }
                else
                {
                    if(++ k < n)
                    {
                        mini += abs(data[i][k].x - data[i][k-1].x);
                    }
                }
            }
        }
        mini = INF;
        for(int j=n-1,k=n-1;k>=0;)
        {
            if(data[i-1][j].x < data[i][k].x)
            {
                if(-- k >= 0)
                {
                    if(mini != INF)
                    {
                        mini += abs(data[i][k].x - data[i][k+1].x);
                        dp[i][k] = min(dp[i][k], mini);
                    }
                }
            }
            else
            {
                mini = min(mini, abs(data[i][k].x - data[i-1][j].x) + dp[i-1][j]);
                dp[i][k] = min(dp[i][k], mini);
                if(j > 0)
                {
                    -- j;
                }
                else
                {
                    if(-- k >= 0)
                    {
                        mini += abs(data[i][k].x - data[i][k+1].x);
                    }
                }
            }
        }
        for(int j=0;j<n;++j)
        {
            dp[i][j] += data[i][j].w;
        }
    }
    ans = INF;
    for(int i=0;i<n;++i)
    {
        ans = min(ans, dp[m-1][i]);
    }
    /*for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            printf("%d/%d %d ", data[i][j].x, data[i][j].w, dp[i][j]);
        }
        printf("\n");
    }*/
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        scanf("%d%d%d", &m, &n, &s);
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &data[i][j].x);
            }
        }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &data[i][j].w);
            }
        }
        solve();
        printf("%d\n", ans);
    }
    return 0;
}
