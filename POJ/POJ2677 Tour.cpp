#include <cstdio>
#include <cstring>
#include <cmath>
const int MAXN = 100;
const double INF = 1e100;

double dp[MAXN][MAXN];
int x[MAXN], y[MAXN];

inline double min(double x, double y)
{
    return x < y ? x : y;
}

inline double getDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(1.0 * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

inline double getDistance(int i, int j)
{
    return getDistance(x[i], y[i], x[j], y[j]);
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &x[i], &y[i]);
            for(int j=0;j<n;++j)
            {
                dp[i][j] = INF;
            }
        }
        dp[1][0] = getDistance(1, 0);
        for(int i=0;i<n-1;++i)
        {
            for(int j=0;j<i;++j)
            {
                dp[i+1][i] = min(dp[i+1][i], dp[i][j] + getDistance(j, i+1));
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + getDistance(i, i+1));
            }
        }
        double ans = INF;
        for(int j=0;j<n-1;++j)
        {
            ans = min(ans, dp[n-1][j] + getDistance(j, n-1));
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
