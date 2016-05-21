#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

int n;
long long a[MAXN][MAXN];
long long t[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int j = 2; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            t[i] = a[i][j] + a[i][j - 1];
        }
        long long d = t[1];
        for (int i = 2; i <= n; ++i) {
            d += a[i][j];
            if (d <= t[i]) {
                t[i] = d;
            } else {
                d = t[i];
            }
        }
        d = t[n];
        for (int i = n - 1; i >= 1; --i) {
            d += a[i][j];
            if (d <= t[i]) {
                t[i] = d;
            } else {
                d = t[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            a[i][j] = t[i];
        }
    }
    long long ans = a[1][n];
    for (int i = 2; i <= n; ++i) {
        ans = min(ans, a[i][n]);
    }
    cout << ans << endl;
    return 0;
}
