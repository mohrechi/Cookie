#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 1000 + 10;

int m, a[MAXN];
int n, b;
int sg[MAXM];

int getSG(int n)
{
    if (sg[n] != -1)
    {
        return sg[n];
    }
    bool visit[MAXM] = {false};
    for (int i = 0; i < m && a[i] <= n; ++i)
    {
        for (int j = 0; j + a[i] <= n; ++j)
        {
            visit[getSG(j) ^ getSG(n - j - a[i])] = true;
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
    while (~scanf("%d", &m))
    {
        memset(sg, -1, sizeof(sg));
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + m);
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &b);
            printf("%d\n", getSG(b) ? 1 : 2);
        }
    }
    return 0;
}
