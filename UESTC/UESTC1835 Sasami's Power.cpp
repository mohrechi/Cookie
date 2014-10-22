#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const long long INF = 0x7fffffffffffffffLL;

long long a[MAXN], b[MAXN];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        double left = -1e100, right = 1e100;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lld", &a[i]);
            b[i] = a[i] - b[i - 1];
            if (i & 1)
            {
                right = min(right, (b[i] - b[i - 1]) * 0.5);
            }
            else
            {
                left = max(left, (b[i - 1] - b[i]) * 0.5);
            }
        }
        if (left > right)
        {
            printf("0\n");
        }
        else
        {
            printf("%.0lf\n", floor(right) - ceil(left) + 1);
        }
    }
    return 0;
}
