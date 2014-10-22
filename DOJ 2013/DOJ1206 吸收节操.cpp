#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int DIRX[4] = {0, 1, 0, -1};
const int DIRY[4] = {1, 0, -1, 0};

int n, rp[MAXN][MAXN], ans;
bool visit[MAXN][MAXN];
int cnt[MAXN][MAXN];

void dfs(int x, int y)
{
    if (!visit[x][y])
    {
        visit[x][y] = true;
        ++cnt[x][y];
        for (int k = 0; k < 4; ++k)
        {
            int tx = x + DIRX[k];
            int ty = y + DIRY[k];
            if (tx >= 1 && tx <= n)
            {
                if (ty >= 1 && ty <= n)
                {
                    if (rp[tx][ty] > rp[x][y])
                    {
                        dfs(tx, ty);
                    }
                }
            }
        }
    }
}

int main()
{
    int q, k, x, y;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &rp[i][j]);
            }
        }
        scanf("%d", &k);
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < k; ++i)
        {
            scanf("%d%d", &x, &y);
            memset(visit, false, sizeof(visit));
            dfs(x, y);
        }
        ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                ans += cnt[i][j] == k;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
