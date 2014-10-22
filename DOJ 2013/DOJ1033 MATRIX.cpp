#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, m;
int a[MAXN][MAXN];
int l[MAXN][MAXN];
int r[MAXN][MAXN];
int u[MAXN][MAXN];

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        memset(a, 0, sizeof(a));
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(u, 0, sizeof(u));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j] == a[i][j - 1])
                {
                    l[i][j] = l[i][j - 1] + 1;
                }
                else
                {
                    l[i][j] = 1;
                }
                if (a[i][j] == a[i - 1][j])
                {
                    u[i][j] = u[i - 1][j] + 1;
                }
                else
                {
                    u[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = m; j >= 1; --j)
            {
                if (a[i][j] == a[i][j + 1])
                {
                    r[i][j] = r[i][j + 1] + 1;
                }
                else
                {
                    r[i][j] = 1;
                }
            }
        }
        int ans = 0;
        for (int j = 1; j <= m; ++j)
        {
            int left = m, right = m;
            int last = 0;
            for (int i = 1; i <= n; ++i)
            {
                left = min(left, l[i][j]);
                right = min(right, r[i][j]);
                if (a[i][j] != a[i + 1][j])
                {
                    ans = max(ans, (left + right - 1) * (i - last));
                    left = right = m;
                    last = i;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
