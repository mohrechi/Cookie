#include <cstdio>
#include <cstring>
const int MAXN = 105;

int sg[MAXN];

int getSG(int n)
{
    if (sg[n] != -1)
    {
        return sg[n];
    }
    bool visit[MAXN] = {false};
    for (int i = 0; i < n; ++i)
    {
        visit[getSG(i)] = true;
        for (int j = i; i + j < n; ++j)
        {
            visit[getSG(i) ^ getSG(j)] = true;
        }
    }
    for (int i = 0; ; ++i)
    {
        if (!visit[i])
        {
            return sg[n] = i;
        }
    }
}

int main()
{
    int n, a;
    memset(sg, -1, sizeof(sg));
    while (~scanf("%d", &n))
    {
        int ans = 0, cnt = 0;
        while (n--)
        {
            scanf("%d", &a);
            ans ^= getSG(a);
            cnt += getSG(a) > 1;
        }
        puts(ans > 0 == cnt > 0 ? "Yes" : "No");
    }
    return 0;
}
