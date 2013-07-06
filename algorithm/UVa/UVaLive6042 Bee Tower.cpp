#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;
const int MAXP = 505;
const int INF = 0x7fffffff;

//#define DEBUG

int N, H, W;
int p[MAXN], h[MAXN];
int dp[MAXN][MAXP];
int maxHeight;

int n;
int pos[MAXN];
int height[MAXN];

int getCost()
{
    int maxWidth = pos[n - 1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j <= maxWidth - (n - i - 1); ++j)
        {
            for (int k = max(0, j - W); k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + abs(pos[i] - j) * height[i]);
            }
            #ifdef DEBUG
            printf("    DP: %d %d %d\n", i, j, dp[i][j]);
            #endif // DEBUG
        }
    }
    int res = INF;
    for (int i = n - 1; i <= maxWidth; ++i)
    {
        res = min(res, dp[n - 1][i]);
    }
    return res;
}

bool getPathLeft(int x)
{
    n = 1;
    pos[0] = p[x];
    height[0] = h[x];
    while (x > 0)
    {
        --x;
        if (h[x + 1] - h[x] <= H && h[x] != maxHeight)
        {
            pos[n] = abs(p[x] - pos[0]);
            height[n] = h[x];
            ++n;
            if (h[x] <= H)
            {
                pos[0] = 0;
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    return false;
}

int judgeLeft(int x)
{
    if (getPathLeft(x))
    {
        #ifdef DEBUG
        printf("Path Left: ");
        for (int i = 0; i < n; ++i)
        {
            printf("(%d %d) ", pos[i], height[i]);
        }
        printf("\n");
        #endif // DEBUG
        return getCost();
    }
    return INF;
}

bool getPathRight(int x)
{
    n = 1;
    pos[0] = p[x];
    height[0] = h[x];
    while (x < N - 1)
    {
        ++x;
        if (h[x - 1] - h[x] <= H && h[x] != maxHeight)
        {
            pos[n] = abs(p[x] - pos[0]);
            height[n] = h[x];
            ++n;
            if (h[x] <= H)
            {
                pos[0] = 0;
                return true;
            }
        }
        else
        {
            return false;
        }
    }
    return false;
}

int judgeRight(int x)
{
    if (getPathRight(x))
    {
        #ifdef DEBUG
        printf("Path Right: ");
        for (int i = 0; i < n; ++i)
        {
            printf("(%d %d) ", pos[i], height[i]);
        }
        printf("\n");
        #endif // DEBUG
        return getCost();
    }
    return INF;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d%d", &N, &H, &W);
        maxHeight = 0;
        for (int i = 0; i < N; ++i)
        {
            scanf("%d%d", &p[i], &h[i]);
            maxHeight = max(maxHeight, h[i]);
        }
        int ans = INF;
        if (maxHeight <= H)
        {
            ans = 0;
        }
        else
        {
            for (int i = 0; i < N; ++i)
            {
                if (h[i] == maxHeight)
                {
                    #ifdef DEBUG
                    printf("Max Height: %d\n", i);
                    #endif // DEBUG
                    ans = min(ans, judgeLeft(i));
                    ans = min(ans, judgeRight(i));
                }
            }
        }
        if (ans == INF)
        {
            ans = -1;
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
