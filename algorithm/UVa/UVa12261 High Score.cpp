#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

char s[MAXN];
int sum[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s + 1);
        int ans = 0;
        int n = strlen(s + 1);
        for (int i = 1; i <= n; ++i)
        {
            ans += min(s[i] - 'A', 'A' + 26 - s[i]);
            sum[i] = sum[i - 1] + (s[i] != 'A');
        }
        sum[n + 1] = sum[n];
        int horizon = n - 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 2; j <= n + 1; ++j)
            {
                if (sum[j - 1] == sum[i])
                {
                    horizon = min(horizon, min((i - 1) * 2 + (n - j + 1), (n - j + 1) * 2 + (i - 1)));
                }
            }
        }
        ans += horizon;
        printf("%d\n", ans);
    }
    return 0;
}
