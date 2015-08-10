#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
const int MOD = 1e9 + 7;

int n, a, b, k;
long long dp[2][MAXN];

void cumulate(long long a[MAXN]) {
    for (int i = 1; i <= b; ++i) {
        (a[i] += a[i - 1]) %= MOD;
    }
}

int main() {
    cin >> n >> a >> b >> k;
    if (a > b) {
        a = n - a + 1;
        b = n - b + 1;
    }
    if (a == b - 1) {
        puts("0");
    } else {
        int curr = 0, prev = 1;
        dp[curr][b - a] = 1;
        cumulate(dp[curr]);
        while (k--) {
            swap(curr, prev);
            for (int i = 1; i < b; ++i) {
                dp[curr][i] = dp[prev][b - 1] - dp[prev][i / 2] - dp[prev][i] + dp[prev][i - 1] + MOD * 2;
                dp[curr][i] %= MOD;
            }
            cumulate(dp[curr]);
        }
        cout << dp[curr][b - 1] << endl;
    }
    return 0;
}
