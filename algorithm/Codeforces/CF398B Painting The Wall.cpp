#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2e3 + 10;

int n, m, a, b;
double dp[MAXN][MAXN];
bool row[MAXN], col[MAXN];

int main()
{
    int u, v;
    scanf("%d%d", &n, &m);
    a = b = n;
    while (m--)
    {
        scanf("%d%d", &u, &v);
        if (!row[u])
        {
            --a;
        }
        if (!col[v])
        {
            --b;
        }
        row[u] = col[v] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] += dp[i - 1][0] + 1.0 * n / i;
        dp[0][i] += dp[0][i - 1] + 1.0 * n / i;
    }
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            dp[i][j] = (n * n + i * j * dp[i - 1][j - 1] + (n - i) * j * dp[i][j - 1] + i * (n - j) * dp[i - 1][j]) / (n * n - (n - i) * (n - j));
        }
    }
    printf("%.10f\n", dp[a][b]);
    return 0;
}
