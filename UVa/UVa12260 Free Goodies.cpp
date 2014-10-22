#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

struct Node
{
    int a, b;
    inline void input()
    {
        scanf("%d%d", &a, &b);
    }
    bool operator <(const Node &node) const
    {
        if (a == node.a)
        {
            return b < node.b;
        }
        return a > node.a;
    }
} node[MAXN];

int n;
int dp1[MAXN][MAXN];
int dp2[MAXN][MAXN];

int main()
{
    int T;
    char dice[10];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s", &n, dice);
        int sum = 0;
        for (int i = 1; i <= n; ++i)
        {
            node[i].input();
            sum += node[i].a;
        }
        sort(node + 1, node + n + 1);
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        bool first = dice[0] == 'J';
        if (first)
        {
            dp1[1][1] = node[1].b;
            dp2[1][1] = node[1].a;
        }
        else
        {
            dp1[1][1] = 0;
            dp2[1][1] = 0;
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= (i + first) >> 1; ++j)
            {
                if (dp1[i - 1][j] > dp1[i - 1][j - 1] + node[i].b)
                {
                    dp1[i][j] = dp1[i - 1][j];
                    dp2[i][j] = dp2[i - 1][j];
                }
                else if (dp1[i - 1][j] < dp1[i - 1][j - 1] + node[i].b)
                {
                    dp1[i][j] = dp1[i - 1][j - 1] + node[i].b;
                    dp2[i][j] = dp2[i - 1][j - 1] + node[i].a;
                }
                else
                {
                    dp1[i][j] = dp1[i - 1][j];
                    dp2[i][j] = min(dp2[i - 1][j], dp2[i - 1][j - 1] + node[i].a);
                }
            }
        }
        printf("%d %d\n", sum - dp2[n][(n + first) >> 1], dp1[n][(n + first) >> 1]);
    }
    return 0;
}
