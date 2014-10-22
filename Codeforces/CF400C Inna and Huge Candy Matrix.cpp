#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

int x[MAXN], y[MAXN];

int main()
{
    int n, m, a, b, c, p;
    scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &c, &p);
    a %= 4;
    b %= 2;
    c %= 4;
    c = (4 - c) % 4;
    for (int i = 0; i < p; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    while (a--)
    {
        for (int i = 0; i < p; ++i)
        {
            int t = y[i];
            y[i] = n + 1 - x[i];
            x[i] = t;
        }
        swap(n, m);
    }
    while (b--)
    {
        for (int i = 0; i < p; ++i)
        {
            y[i] = m + 1 - y[i];
        }
    }
    while (c--)
    {
        for (int i = 0; i < p; ++i)
        {
            int t = y[i];
            y[i] = n + 1 - x[i];
            x[i] = t;
        }
        swap(n, m);
    }
    for (int i = 0; i < p; ++i)
    {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}
