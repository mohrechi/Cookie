#include <cstdio>
const int MAXN = 100005;

int a[MAXN];

int main()
{
    int t, n, m, u, v;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", a[v + 1] - a[u]);
        }
    }
    return 0;
}
