#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXC = 5000 + 1;
const int MOD = 1e9 + 7;

int c[MAXC][MAXC];

int C(int n, int m)
{
    if (m > n) return 0;
    if (m == 0) return 1;
    if (m < 0) return 0;
    if (c[n][m]) return c[n][m];
    if (m > (n >> 1)) return c[n][m] = C(n, n - m);
    return c[n][m] = (C(n - 1, m - 1) + C(n - 1, m)) % MOD;
}

int t, n, x, k;
int cl[MAXC];

int main()
{
    scanf("%d%d", &t, &n);
    for (int i = 0; i < t; ++i)
    {
        scanf("%d", &cl[i]);
    }
    scanf("%d%d", &x, &k);
    int a = 0, b = 0, m = -1;
    --x;
    for (int i = 0; i < t; ++i)
    {
        if (cl[i] < cl[x]) ++a;
        else if (cl[i] > cl[x]) ++b;
        else ++m;
    }
    int ans = 0;
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            ans +=1LL * C(a, k - 1 - j) * C(b, n - k - i + j) % MOD * C(m, i) % MOD;
            ans %= MOD;
        }
    }
    printf("%d\n", ans);
    return 0;
}
