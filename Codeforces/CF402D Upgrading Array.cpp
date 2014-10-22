#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 10;

int n, m;
int a[MAXN], b, g[MAXN];
set<int> bad;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int getScore(int x)
{
    int score = 0;
    while ((x & 1) == 0)
    {
        x >>= 1;
        bad.find(2) == bad.end() ? ++score : --score;
    }
    for (int i = 3; i * i <= x && x != 1; i += 2)
    {
        while (x % i == 0)
        {
            bad.find(i) == bad.end() ? ++score : --score;
            x /= i;
        }
    }
    if (x != 1)
    {
        bad.find(x) == bad.end() ? ++score : --score;
    }
    return score;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        if (i == 0)
        {
            g[0] = a[0];
        }
        else
        {
            g[i] = gcd(g[i - 1], a[i]);
        }
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &b);
        bad.insert(b);
    }
    int div = 1, ans = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (getScore(g[i] / div) <= 0)
        {
            div = g[i];
        }
        ans += getScore(a[i] / div);
    }
    printf("%d\n", ans);
    return 0;
}
