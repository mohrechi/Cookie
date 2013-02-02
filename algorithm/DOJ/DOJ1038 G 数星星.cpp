#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int h, w, n, q;
bool visit[MAXN][MAXN];
int sum[MAXN][MAXN];

int main()
{
    int x, y, r;
    while(~scanf("%d%d%d%d", &h, &w, &n, &q))
    {
        memset(visit, false, sizeof(visit));
        memset(sum, 0, sizeof(sum));
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &x, &y);
            visit[x][y] = true;
        }
        for(int i=0;i<=h;++i)
        {
            sum[i][0] = visit[i][0];
            for(int j=1;j<=w;++j)
            {
                sum[i][j] = sum[i][j - 1] + visit[i][j];
            }
        }
        while(q--)
        {
            scanf("%d%d%d", &x, &y, &r);
            int ans = 0;
            int d = max(0, x - r);
            int u = min(h, x + r);
            r *= r;
            for(int i=d;i<=u;++i)
            {
                int wx = abs(i - x);
                int wy = sqrt(r - wx * wx);
                int l = max(0, y - wy);
                int r = min(w, y + wy);
                if(l == 0)
                {
                    ans += sum[i][r];
                }
                else
                {
                    ans += sum[i][r] - sum[i][l - 1];
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
