#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 10000 + 10;

int k, s[MAXN];
int m, l, h;
int sg[MAXM];

int getSG(int h)
{
    if (sg[h] != -1)
    {
        return sg[h];
    }
    bool visit[MAXN], v = 0;
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < k; ++i)
    {
        if (h - s[i] >= 0)
        {
            int t = getSG(h - s[i]);
            if (t < MAXN)
            {
                visit[t] = true;
            }
        }
    }
    for (int i = 0; i < MAXN; ++i)
    {
        if (!visit[i])
        {
            return sg[h] = i;
        }
    }
}

int main()
{
    while (scanf("%d", &k), k)
    {
        for (int i = 0; i < k; ++i)
        {
            scanf("%d", &s[i]);
        }
        scanf("%d", &m);
        memset(sg, -1, sizeof(sg));
        sg[0] = 0;
        for (int i = 0; i < m; ++i)
        {
            int ans = 0;
            scanf("%d", &l);
            for (int j = 0; j < l; ++j)
            {
                scanf("%d", &h);
                ans ^= getSG(h);
            }
            putchar(ans ? 'W' : 'L');
        }
        putchar('\n');
    }
    return 0;
}
