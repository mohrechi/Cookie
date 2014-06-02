#include <cstdio>
#include <cstring>
const int MAXN = 105;

int main()
{
    int n, a[MAXN], cnt[MAXN];
    while (scanf("%d", &n), n)
    {
        memset(cnt,  0, sizeof(cnt));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            ++cnt[a[i]];
        }
        bool win = false;
        for (int i = 0; i < MAXN; ++i)
        {
            if (cnt[i] & 1)
            {
                win = true;
                break;
            }
        }
        printf("%d\n", win);
    }
    return 0;
}
