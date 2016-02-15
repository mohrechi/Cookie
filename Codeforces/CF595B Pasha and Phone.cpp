#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXK = 15;
const int MOD = 1e9 + 7;

int n, m, k;
long long ten[MAXK];
long long a[MAXN], b[MAXN];

int main() {
    ten[0] = 1;
    for (int i = 1; i < MAXK; ++i) {
        ten[i] = ten[i - 1] * 10 % MOD;
    }
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int m = n / k;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    long long ans = 1;
    for (int i = 0; i < m; ++i) {
        long long total = (ten[k] - 1) / a[i] + 1;
        long long upper = ((b[i] + 1) * ten[k - 1] - 1) / a[i] + 1;
        if (b[i] == 0) {
            ans = ans * (total - upper) % MOD;
        } else {
            long long lower = (b[i] * ten[k - 1] - 1) / a[i] + 1;
            ans = ans * (total - (upper - lower)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
