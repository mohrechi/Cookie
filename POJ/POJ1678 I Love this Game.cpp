#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;
const int INF = 0x3f3f3f3f;

int n, a, b;
int num[MAXN], dp[MAXN];

int getDP(int x)
{
    if (dp[x] != -INF)
    {
        return dp[x];
    }
    int ans = INF;
    for (int i = x + 1; i < n; ++i)
    {
        if (a <= num[i] - num[x] && num[i] - num[x] <= b)
        {
            ans = min(ans, num[x] - getDP(i));
        }
    }
    if (ans == INF)
    {
        return dp[x] = num[x];
    }
    return dp[x] = ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &a, &b);
        for (int i = 0; i < n; ++i)
        {
            dp[i] = -INF;
            scanf("%d", &num[i]);
        }
        sort(num, num + n);
        int ans = -INF;
        for (int i = 0; i < n; ++i)
        {
            if (a <= num[i] && num[i] <= b)
            {
                ans = max(ans, getDP(i));
            }
        }
        printf("%d\n", ans == -INF ? 0 : ans);
    }
    return 0;
}
