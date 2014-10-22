#include <cstdio>

inline int getCount(int c, int n)
{
    if(c <= n)
    {
        return c + 40 - n;
    }
    return c - n;
}

int main()
{
    int dial, a, b, c, ans;
    while(scanf("%d%d%d%d", &dial, &a, &b, &c), dial||a||b||c)
    {
        ans = 120 * 9;
        ans += getCount(dial, a) * 9;
        ans += getCount(b, a) * 9;
        ans += getCount(b, c) * 9;
        printf("%d\n", ans);
    }
    return 0;
}
