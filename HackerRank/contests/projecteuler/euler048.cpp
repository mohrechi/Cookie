#include <bits/stdc++.h>
using namespace std;
const long long MOD = 10000000000LL;

long long fast_mul(long long x, long long y) {
    unsigned long long a = x >> 30;
    unsigned long long b = x & ((1LL << 30) - 1);
    unsigned long long c = y >> 30;
    unsigned long long d = y & ((1LL << 30) - 1);
    unsigned long long aa = a * c % MOD;
    aa <<= 30;
    aa %= MOD;
    aa <<= 30;
    aa %= MOD;
    unsigned long long bb = a * d % MOD;
    bb <<= 30;
    bb %= MOD;
    unsigned long long cc = b * c % MOD;
    cc <<= 30;
    cc %= MOD;
    unsigned long long dd = b * d % MOD;
    return (aa + bb + cc + dd) % MOD;
}

long long fast_pow(long long x, long long y) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if (y & (1LL << i)) {
            ret = fast_mul(ret, x);
        }
        x = fast_mul(x, x);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    long long ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += fast_pow(i, i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}

