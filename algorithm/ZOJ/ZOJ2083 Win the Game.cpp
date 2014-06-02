#include <cstdio>
#include <cstring>
const int MAXN = 100;

int sg[MAXN];

int getSG(int n)
{
    if (sg[n] != -1)
    {
        return sg[n];
    }
    bool visit[MAXN] = {false};
    for (int i = 0; i + 2 <= n; ++i)
    {
        visit[getSG(i) ^ getSG(n - i - 2)] = true;
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
        int ans = 0;
        while (n--)
        {
            scanf("%d", &a);
            ans ^= getSG(a);
        }
        puts(ans ? "Yes" : "No");
    }
    return 0;
}
