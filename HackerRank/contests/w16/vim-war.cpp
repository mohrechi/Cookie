#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 20 + 1;
const int MOD = 1e9 + 7;

int n, m;
char s[MAXN][MAXM];
char target[MAXM];
long long cnt[1<<MAXM];

long long fastPow(long long x, long long y) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if (y & (1LL << i)) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    scanf("%s", target);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int b = 0, x = 0;
        bool valid = true;
        for (int j = 0; target[j]; ++j) {
            if (s[i][j] == '1') {
                if (target[j] == '0') {
                    valid = false;
                    break;
                }
                x |= 1 << b;
            }
            if (target[j] == '1') {
                ++b;
            }
        }
        if (valid) {
            ++cnt[x];
            m = b;
            ++sum;
        }
    }
    if (m == 0) {
        if (sum == 0) {
            cout << 1 << endl;
        } else {
            cout << fastPow(2, sum) - 1 << endl;
        }
        return 0;
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < (1 << m); ++i) {
            if (i & (1 << j)) {
                cnt[i] += cnt[i ^ (1 << j)];
            }
        }
    }
    for (int i = 0; i < (1 << m); ++i) {
        cnt[i] = fastPow(2, cnt[i]);
    }
    long long ans = 0;
    for (int i = 0; i < (1 << m); ++i) {
        int d = m - __builtin_popcount(i);
        if (d & 1) {
            ans = ((ans - cnt[i]) % MOD + MOD) % MOD;
        } else {
            ans = (ans + cnt[i]) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
