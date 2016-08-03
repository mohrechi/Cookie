#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;

int n, m;
int sum[MAXN][MAXN];
int a, b;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> sum[i][j];
        }
    }
    cin >> a >> b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    int ans = sum[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + a <= n && j + b <= m) {
                ans = min(ans, sum[i + a][j + b] - sum[i + a][j] - sum[i][j + b] + sum[i][j]);
            }
            if (i + b <= n && j + a <= m) {
                ans = min(ans, sum[i + b][j + a] - sum[i + b][j] - sum[i][j + a] + sum[i][j]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
