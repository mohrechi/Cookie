#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

int n;
long long sum[MAXN];
long long A, B, C;
long long dp[MAXN];
int queue[MAXN];

long long calcValue(long long x)
{
    return A * x * x + B * x + C;
}

long long calcValue(int j, int k)
{
    return (dp[j] - dp[k]) + A * (sum[j] * sum[j] - sum[k] * sum[k]) - B * (sum[j] - sum[k]);
}

long long solve()
{
    int front = 0, rear = 0;
    queue[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (front < rear && calcValue(queue[front], queue[front + 1]) <= 2 * A * sum[i] * (sum[queue[front]] - sum[queue[front + 1]]))
        {
            ++ front;
        }
        int u = queue[front];
        dp[i] = dp[u] + calcValue(sum[i] - sum[u]);
        while (front < rear && calcValue(queue[rear - 1], queue[rear]) * (sum[queue[rear]] - sum[i]) <= calcValue(queue[rear], i) * (sum[queue[rear - 1]] - sum[queue[rear]]))
        {
            -- rear;
        }
        queue[++rear] = i;
    }
    return dp[n];
}

int main()
{
    while (~scanf("%d", &n))
    {
        scanf("%lld%lld%lld", &A, &B, &C);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &sum[i]);
            sum[i] += sum[i - 1];
        }
        printf("%lld\n", solve());
    }
    return 0;
}
