#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

int n, a[MAXN], b;
int sum[MAXN * 3];

void build(int x, int l, int r)
{
    sum[x] = r - l + 1;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
}

void update(int x, int l, int r, int pos)
{
    sum[x] -= 1;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        update(x << 1, l, mid, pos);
    }
    else
    {
        update((x << 1) + 1, mid + 1, r, pos);
    }
}

int query(int x, int l, int r, int k)
{
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) >> 1;
    if (k <= sum[x << 1])
    {
        return query(x << 1, l, mid, k);
    }
    return query((x << 1) + 1, mid + 1, r, k - sum[x << 1]);
}

int main()
{
    while (~scanf("%d", &n))
    {
        build(1, 1, n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &b);
            int pos = query(1, 1, n, b + 1);
            a[pos] = i;
            update(1, 1, n, pos);
        }
        for (int i = 1; i <= n; ++i)
        {
            if (i > 1)
            {
                putchar(' ');
            }
            printf("%d", a[i]);
        }
        putchar('\n');
    }
    return 0;
}
