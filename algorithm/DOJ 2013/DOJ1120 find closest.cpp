#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int INF = 0x7fffffff;

int main()
{
    int t, n, a[MAXN], ans;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ans = INF;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            for (int j = 0; j < i; ++j)
            {
                ans = min(ans, abs(a[i] - a[j]));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
