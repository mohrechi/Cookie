#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 40005;

int n, m;
long long c[MAXN];

inline int lowbit(const int &x)
{
    return x & (-x);
}

void update(int x, long long value)
{
    while (x < MAXN)
    {
        c[x] += value;
        x += lowbit(x);
    }
}

long long sum(int x)
{
    long long res = 0;
    while (x > 0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

long long sum(int a, int b)
{
    return sum(b) - sum(a - 1);
}

int main()
{
    int a, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        update(i, a);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &a, &b);
        printf("%lld\n", sum(a, b));
    }
    return 0;
}
