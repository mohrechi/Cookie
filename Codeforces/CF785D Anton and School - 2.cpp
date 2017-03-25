#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
const int MOD = 1e9 + 7;

long long fact[MAXN];

void init() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

long long powMod(long long x, long long y) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if ((1LL << i) & y) {
            ret = (ret * x) % MOD;
        }
        x = (x * x) % MOD;
    }
    return ret;
}

inline long long invMod(long long x) {
    return powMod(x, MOD - 2);
}

inline long long comMod(long long n, long long m) {
    return fact[n] * invMod(fact[m]) % MOD * invMod(fact[n - m]) % MOD;
}

int lNum, rNum[MAXN];

int main() {
    string s;
    init();
    cin >> s;
    for (int i = s.length() - 1; i >= 0; --i) {
        rNum[i] = rNum[i + 1] + (s[i] == ')');
    }
    long long ans = 0;
    for (int i = 0; i < (int)s.length(); ++i) {
        if (s[i] == '(') {
            ++lNum;
            ans = (ans + comMod(lNum + rNum[i] - 1, lNum)) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
