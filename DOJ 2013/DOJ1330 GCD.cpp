#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

char sign[MAXN];
long long fact[MAXN * 2];

void initFact() {
    fact[0] = 1;
    for (int i = 1; i < MAXN * 2; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
}

void initSign() {
    sign[1] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i + i; j < MAXN; j += i) {
            sign[j] -= sign[i];
        }
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

long long inverse(long long x) {
    return fastPow(x, MOD - 2);
}

long long combination(long long n, long long m) {
    return fact[n] * inverse(fact[m]) % MOD * inverse(fact[n - m]) % MOD;
}

int main() {
    int T, N, K;
    initFact();
    initSign();
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        long long ans = 0;
        for (int i = 1; i <= N; ++i) {
            ans = (ans + sign[i] * combination(N / i + K - 1, K) + MOD) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
