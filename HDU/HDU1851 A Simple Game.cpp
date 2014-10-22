#include <cstdio>
#include <cstring>
const int MAXN = 30;

int sg[MAXN][MAXN];

int getSG(int m, int l)
{
    if (sg[m][l] != -1)
    {
        return sg[m][l];
    }
    bool visit[MAXN] = {false};
    for (int i = 1; i <= l && i <= m; ++i)
    {
        visit[getSG(m - i, l)] = true;
    }
    for (int i = 0; ; ++i)
    {
        if (!visit[i])
        {
            return sg[m][l] = i;
        }
    }
}

int main()
{
    int t, n, m, l;
    memset(sg, -1, sizeof(sg));
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d%d", &m, &l);
            ans ^= getSG(m, l);
        }
        puts(ans ? "No" : "Yes");
    }
    return 0;
}
