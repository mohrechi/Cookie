#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 500 + 10;

int n, m, a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        for (int j = 1; j <= m; ++j) {
            cin >> b[j];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            int maxDp = 0;
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (a[i] > b[j]) {
                    if (maxDp < dp[i - 1][j]) {
                        maxDp = dp[i - 1][j];
                    }
                }
                if (a[i] == b[j]) {
                    dp[i][j] = maxDp + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
        if (T) {
            cout << endl;
        }
    }
    return 0;
}
