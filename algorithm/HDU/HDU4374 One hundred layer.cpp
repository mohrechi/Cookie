#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXM = 10005;
const int INF = 1000000000;

struct Node
{
    int score, index;
};

int n, m, x, t;
int floor[MAXN][MAXM];
int dp[MAXN][MAXM];
int total[MAXM];
Node queue[MAXM];

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&x,&t))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                scanf("%d", &floor[i][j]);
                dp[i][j] = - INF;
            }
        }
        int sum = 0;
        for(int i=0, j=x;i <= t && j >= 1;++i, --j)
        {
            sum += floor[0][j];
            dp[0][j] = sum;
        }
        sum = 0;
        for(int i=0, j=x;i <= t && j <= m;++i, ++j)
        {
            sum += floor[0][j];
            dp[0][j] = sum;
        }
        for(int i=1;i<n;++i)
        {
            total[0] = 0;
            int front = 0, rear = 0;
            for(int j=1;j<=m;++j)
            {
                total[j] = total[j-1] + floor[i][j];
                while(j - queue[front].index > t && front < rear)
                {
                    ++ front;
                }
                int temp = dp[i-1][j] - total[j-1];
                while(front < rear && queue[rear-1].score <= temp)
                {
                    -- rear;
                }
                queue[rear].score = temp;
                queue[rear++].index = j;
                dp[i][j] = max(dp[i][j], queue[front].score + total[queue[front].index-1] + total[j] - total[queue[front].index - 1]);
            }
            total[m+1] = 0;
            front = 0, rear = 0;
            for(int j=m;j>=1;--j)
            {
                total[j] = total[j+1] + floor[i][j];
                while(queue[front].index - j > t && front < rear)
                {
                    ++ front;
                }
                int temp = dp[i-1][j] - total[j+1];
                while(front < rear && queue[rear-1].score <= temp)
                {
                    -- rear;
                }
                queue[rear].score = temp;
                queue[rear++].index = j;
                dp[i][j] = max(dp[i][j], queue[front].score + total[queue[front].index+1] + total[j] - total[queue[front].index + 1]);
            }
        }
        int ans = - INF;
        for(int i=1;i<=m;++i)
        {
            ans = max(ans, dp[n-1][i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
