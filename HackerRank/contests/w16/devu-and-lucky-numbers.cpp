#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = MAXN * 3;
const int MOD = 1e9 + 7;

long long fact[MAXM];
long long powT[MAXM];
long long num[MAXM];
long long pre[MAXN][MAXN][MAXN];

inline long long fastPow(long long x, long long y) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if (y & (1LL << i)) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
    }
    return ret;
}

inline long long inverse(long long x) {
    return fastPow(x, MOD - 2);
}

inline long long combine(long long m, long long n) {
    return fact[n] * inverse(fact[m]) % MOD * inverse(fact[n - m]) % MOD;
}

inline long long combine(long long x, long long y, long long z) {
    return combine(y, x + y) * combine(z, x + y + z) % MOD;
}

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int total = a[0] + a[1] + a[2];
    fact[0] = 1;
    powT[0] = 1;
    for (int i = 1; i <= total; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        powT[i] = powT[i - 1] * 10 % MOD;
    }
    for (int i = 0; i <= a[0]; ++i) {
        for (int j = 0; j <= a[1]; ++j) {
            for (int k = 0; k <= a[2]; ++k) {
                pre[i][j][k] = combine(i, j, k);
            }
        }
    }
    long long ans = 0;
    for (int d = 0; d < 3; ++d) {
        if (a[d]) {
            --a[d];
            memset(num, 0, sizeof(num));
            for (int i = 0; i <= a[0]; ++i) {
                for (int j = 0; j <= a[1]; ++j) {
                    for (int k = 0; k <= a[2]; ++k) {
                        num[i + j + k] += pre[i][j][k];
                        num[i + j + k] %= MOD;
                    }
                }
            }
            ++a[d];
            for (int i = 1; i <= total; ++i) {
                num[i] += num[i - 1];
                num[i] %= MOD;
            }
            for (int i = 0; i < total; ++i) {
                ans += (d + 4) * powT[i] % MOD * ((num[total - 1] - (i ? num[i - 1] : 0) + MOD) % MOD);
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
