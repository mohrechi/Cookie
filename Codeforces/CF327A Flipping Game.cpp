#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n;
int a[MAXN];
int sum0[MAXN];
int sum1[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            sum0[i] = sum0[i - 1] + (a[i] == 0);
            sum1[i] = sum1[i - 1] + (a[i] == 1);
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                ans = max(ans, sum1[n] - (sum1[j] - sum1[i - 1]) + (sum0[j] - sum0[i - 1]));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
