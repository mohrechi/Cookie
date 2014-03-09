#include <cstdio>
const int MAXN = 100 + 10;

int n;
int l[MAXN], r[MAXN];
bool visit[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &l[i], &r[i]);
        if (i)
        {
            for (int j = l[i]; j < r[i]; ++j)
            {
                visit[j] = true;
            }
        }
    }
    int ans = 0;
    for (int i = l[0]; i < r[0]; ++i)
    {
        ans += 1 - visit[i];
    }
    printf("%d\n", ans);
    return 0;
}
