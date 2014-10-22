#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 1;

int v[MAXN], ans[MAXN];

int main()
{
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }
    sort(v, v + n);
    int lp = 0, rp = n - 1;
    int li = 0, ri = n - 1;
    while (lp <= rp)
    {
        if (lp == rp)
        {
            ans[li] = v[lp];
            break;
        }
        if (v[lp] + v[rp] > s)
        {
            ans[li++] = v[lp++];
            ans[li++] = v[rp--];
        }
        else
        {
            ans[ri--] = v[lp++];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        ++cnt;
        if (i != n - 1)
        {
            if (ans[i] + ans[i + 1] <= s)
            {
                ++i;
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++i)
    {
        if (i)
        {
            putchar(' ');
        }
        printf("%d", ans[i]);
    }
    putchar('\n');
    return 0;
}
