#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

long long fact[MAXN];
long long pow10[MAXN];
long long factor[MAXN];

void init() {
    fact[0] = 1;
    pow10[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        pow10[i] = pow10[i - 1] * 10 % MOD;
    }
}

long long fastPow(long long x, long long y) {
    long long ret = 1;
    for (int i = 0; (1 << i) <= y; ++i) {
        if (y & (1 << i)) {
            ret = ret * x % MOD;
        }
        x = x * x % MOD;
    }
    return ret;
}

long long getC(int n, int m) {
    if (n < m) {
        return 0;
    }
    return fact[n] * fastPow(fact[m] * fact[n - m] % MOD, MOD - 2) % MOD;
}

int main() {
    int n, k;
    string d;
    cin >> n >> k;
    cin >> d;
    init();
    for (int l = 0; l < n; ++l) {
        factor[l] = pow10[l] * getC(n - l - 2, k - 1) % MOD;
        if (l) {
            factor[l] += factor[l - 1];
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int di = d[n - i - 1] - '0';
        if (di) {
            if (i) {
                ans += di * factor[i - 1] % MOD;
            }
            ans += di * pow10[i] * getC(n - i - 1, k) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
