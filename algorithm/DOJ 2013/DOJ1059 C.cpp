#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;

struct Seg
{
    int u, v;
    bool operator <(const Seg &seg) const
    {
        if (u == seg.u)
        {
            return v < seg.v;
        }
        return u < seg.u;
    }
} seg[MAXN];

int countDigit(int x)
{
    if (x == 0)
    {
        return 1;
    }
    int cnt = 0;
    while (x)
    {
        ++cnt;
        x /= 10;
    }
    return cnt;
}

int reverse(char x[20])
{
    int res = 0;
    int len = strlen(x);
    for (int i = len - 1; i >= 0; --i)
    {
        res = res * 10 + x[i] - '0';
    }
    return res;
}

int getSmall(int x)
{
    int cnt = countDigit(x);
    while (cnt <= 9)
    {
        x = x * 10;
        ++cnt;
    }
    return x;
}

int getBig(int x)
{
    int cnt = countDigit(x);
    while (cnt <= 9)
    {
        x = x * 10 + 9;
        ++cnt;
    }
    return x;
}

int main()
{
    int n;
    char a[20];
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", a);
            int len = strlen(a);
            a[len] = '1';
            a[len + 1] = 0;
            int x = reverse(a);
            seg[i].u = getSmall(x);
            seg[i].v = getBig(x);
        }
        sort(seg, seg + n);
        int count = 0;
        int left = seg[0].u, right = seg[0].v;
        for (int i = 1; i < n; ++i)
        {
            if (seg[i].u > right)
            {
                count += right - left + 1;
                left = seg[i].u;
                right = seg[i].v;
            }
            else
            {
                right = max(right, seg[i].v);
            }
        }
        count += right - left + 1;
        printf("%.4lf\n", count / 10000.0);
    }
    return 0;
}
