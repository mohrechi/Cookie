#include <map>
#include <cstdio>
using namespace std;
const int MAXN = 500 + 10;
const int MOD = 1e9 + 7;

int c[MAXN * 32][MAXN];
map<int, int> p;

int main()
{
    int n, a;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        for (int j = 2; j * j <= a; ++j)
        {
            while (a % j == 0)
            {
                ++p[j];
                a /= j;
            }
        }
        if (a > 1)
        {
            ++p[a];
        }
    }
    for (int i = 0; i < n * 32; ++i)
    {
        c[i][0] = 1;
    }
    for (int i = 1; i < n * 32; ++i)
    {
        for (int j = 1; j < n; ++j)
        {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    long long ans = 1;
    for (auto it : p)
    {
        ans = (ans * c[it.second + n - 1][n - 1]) % MOD;
    }
    printf("%I64d\n", ans);
    return 0;
}
