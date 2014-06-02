#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100;

int n, m;
int sg[MAXN][MAXN];
char board[MAXN][MAXN];

int getSG(int p, int q)
{
    if (sg[p][q] != -1)
    {
        return sg[p][q];
    }
    if (p == 0) return sg[p][q] = q;
    if (q == 0) return sg[p][q] = p;
    bool visit[MAXN * MAXN] = {false};
    for (int u = 0; u < p; ++u)
    {
        for (int v = 0; v < q; ++v)
        {
            visit[getSG(u, q) ^ getSG(p, v)] = true;
        }
    }
    for (int i = 0; ; ++i)
    {
        if (!visit[i])
        {
            return sg[p][q] = i;
        }
    }
}

int main()
{
    memset(sg, -1, sizeof(sg));
    while (scanf("%d%d", &n, &m), n || m)
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", board[i]);
            for (int j = 0; j < m; ++j)
            {
                if (board[i][j] == '#')
                {
                    ans ^= getSG(i, j);
                }
            }
        }
        puts(ans ? "John" : "Jack");
    }
    return 0;
}
