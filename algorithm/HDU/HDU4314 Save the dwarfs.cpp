#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2005;
const int INF = 1000000000;

struct Node
{
    int a, b;
    bool operator < (const Node &node) const
    {
        return (a + b) > (node.a + node.b);
    }
}node[MAXN];
int n, h;
int dp[MAXN][MAXN];
int sumA[MAXN];

inline int min(const int &x, const int &y)
{
    return x < y ? x : y;
}

inline int max(const int &x, const int &y)
{
    return x > y ? x : y;
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d", &node[i].a, &node[i].b);
        }
        scanf("%d", &h);
        sort(node + 1, node + n + 1);
        sumA[1] = node[1].a;
        for(int i=2;i<=n;++i)
        {
            sumA[i] = sumA[i-1] + node[i].a;
        }
        memset(dp, 0, sizeof(dp));
        for(int i=0;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                dp[i][j] = INF;
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=i;++j)
            {
                dp[i][j] = min(dp[i-1][j] - node[i].a, max(dp[i-1][j-1], h - sumA[i] - node[i].b));
            }
        }
        for(int i=n;i>=0;--i)
        {
            if(dp[n][i] <= 0)
            {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}
