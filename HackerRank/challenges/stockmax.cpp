#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000 + 10;

long long price[MAXN];
long long dp[MAXN];

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &price[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[n - 1] = price[n - 1];
        for (int i = n - 2; i > 0; --i) {
            dp[i] = max(price[i], dp[i + 1]);
        }
        long long sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (price[i] < dp[i + 1]) {
                sum += dp[i + 1] - price[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
