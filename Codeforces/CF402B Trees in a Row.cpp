#include <cstdio>
const int MAXN = 1000 + 10;

int n, k;
int a[MAXN], cnt[MAXN];

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (a[j] == i + k * (j - 1))
            {
                ++cnt[i];
            }
        }
    }
    int start = 1;
    for (int i = 2; i <= 1000; ++i)
    {
        if (cnt[i] > cnt[start])
        {
            start = i;
        }
    }
    int num = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] != start + k * (i - 1))
        {
            ++num;
        }
    }
    printf("%d\n", num);
    for (int i = 1; i <= n; ++i)
    {
        int expect = start + k * (i - 1);
        if (a[i] > expect)
        {
            printf("- %d %d\n", i, a[i] - expect);
        }
        else if (a[i] < expect)
        {
            printf("+ %d %d\n", i, expect - a[i]);
        }
    }
    return 0;
}
