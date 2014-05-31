#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int nim[2][2] = {0, 0, 0, 1};

int nimMultiLowest(int x)
{
    for (int i = 0; ; ++i)
    {
        if ((1 << (1 << i)) > x)
        {
            return 1 << (1 << (i - 1));
        }
    }
}

int nimMultiPower(int x, int y)
{
    if (x < 2 && y < 2)
    {
        return nim[x][y];
    }
    int m = nimMultiLowest(x);
    int p = x / m;
    int s = y / m;
    int t = y - s * m;
    int d1 = nimMultiPower(p, s);
    int d2 = nimMultiPower(p, t);
    return (m * (d1 ^ d2)) ^ nimMultiPower(m >> 1, d1);
}

int nimMulti(int x, int y)
{
    if (x < 2 && y < 2)
    {
        return nim[x][y];
    }
    if (x < y)
    {
        return nimMulti(y, x);
    }
    int m = nimMultiLowest(x);
    int p = x / m;
    int q = x - p * m;
    int s = y / m;
    int t = y - s * m;
    int c1 = nimMulti(p, s);
    int c2 = nimMulti(p, t) ^ nimMulti(q, s);
    int c3 = nimMulti(q, t);
    return (m * (c1 ^ c2)) ^ c3 ^ nimMultiPower(m >> 1, c1);
}

int main()
{
    int T, n, x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &x, &y);
            ans ^= nimMulti(x, y);
        }
        puts(ans ? "Have a try, lxhgww." : "Don't waste your time.");
    }
    return 0;
}
