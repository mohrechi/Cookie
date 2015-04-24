#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;


int main() {
    int T, c, a[MAXN], p[MAXN], dp[MAXN];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &c);
        a[0] = 0;
        for (int i = 1; i <= c; ++i) {
            scanf("%d%d", &a[i], &p[i]);
            a[i] += a[i - 1];
        }
        dp[0] = 0;
        for (int i = 1; i <= c; ++i) {
            dp[i] = 0x7fffffff;
            for (int j = 0; j < i; ++j) {
                dp[i] = min(dp[i], dp[j] + (a[i] - a[j] + 10) * p[i]);
            }
        }
        printf("%d\n", dp[c]);
    }
    return 0;
}
