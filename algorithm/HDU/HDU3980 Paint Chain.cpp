#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int sg[MAXN][MAXN];

int getSG(int n, int m)
{
    if (n < 0)
    {
        return 1;
    }
    if (sg[n][m] != -1)
    {
        return sg[n][m];
    }
    if (n < m)
    {
        return sg[n][m] = 0;
    }
    bool visit[MAXN];
    memset(visit, false, sizeof(visit));
    for (int i = 0; n - m - i >= 0; ++i)
    {
        visit[getSG(i, m) ^ getSG(n - m - i, m)] = true;
    }
    for (int i = 0; i < MAXN; ++i)
    {
        if (!visit[i])
        {
            return sg[n][m] = i;
        }
    }
}

int main()
{
    int T, n, m;
    scanf("%d", &T);
    memset(sg, -1, sizeof(sg));
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d", &n, &m);
        printf("Case #%d: %s\n", t, getSG(n - m, m) ? "abcdxyzk" : "aekdycoin");
    }
    return 0;
}
