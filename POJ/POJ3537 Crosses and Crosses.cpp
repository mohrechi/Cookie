#include <cstdio>
#include <cstring>
const int MAXN = 2005;

int sg[MAXN];

int getSG(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    if (sg[n] != -1)
    {
        return sg[n];
    }
    bool visit[MAXN] = {false};
    for (int i = 1; i <= n; ++i)
    {
        visit[getSG(i - 3) ^ getSG(n - i - 2)] = true;
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
    int n;
    memset(sg, -1, sizeof(sg));
    while (~scanf("%d", &n))
    {
        printf("%d\n", 2 - (getSG(n) > 0));
    }
    return 0;
}
