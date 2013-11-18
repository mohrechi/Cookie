#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

long long x[MAXN], y[MAXN];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &x[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%lld", &y[i]);
        }
        sort(x, x + n);
        sort(y, y + n);
        long long ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans += x[i] * y[n - i - 1];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
