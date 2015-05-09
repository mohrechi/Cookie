#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const int MAXK = 100 + 10;

int n, m, k;
long long dp[MAXN][MAXK];
long long powm[MAXN], powk[MAXN];
long long ans;

int get(int len, int mod) {
    if (dp[len][mod] == -1) {
        if (len == 0) {
            dp[len][mod] = (mod == 0 ? 1 : 0);
        } else {
            if (mod == 0) {
                dp[len][mod] = get(len - 1, mod);
                for (int i = 1; i < 10; ++i) {
                    long long num = n - len == 0 ? 1 : powm[n - len - 1] * 9;
                    ans += get(len - 1, (mod - i * powk[len - 1] % k + k) % k) * num;
                    ans %= m;
                }
            } else {
                dp[len][mod] = 0;
                for (int i = 0; i < 10; ++i) {
                    dp[len][mod] += get(len - 1, (mod - i * powk[len - 1] % k + k) % k);
                    dp[len][mod] %= m;
                }
            }
        }
    }
    return dp[len][mod];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k >> m;
    memset(dp, -1, sizeof(dp));
    powm[0] = 1, powk[0] = 1;
    for (int i = 1; i <= n; ++i) {
        powm[i] = 10 * powm[i - 1] % m;
        powk[i] = 10 * powk[i - 1] % k;
    }
    powm[0] = 1;
    ans = 0;
    get(n, 0);
    cout << ans << endl;
    return 0;
}
