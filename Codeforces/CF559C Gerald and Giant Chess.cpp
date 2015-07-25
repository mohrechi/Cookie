#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;
const int MAXW = 1e5 + 10;
const int MOD = 1e9 + 7;

int h, w, n;
struct Point {
    int x, y;
    bool operator <(const Point &point) const {
        if (x == point.x) {
            return y < point.y;
        }
        return x < point.x;
    }
} point[MAXN];

long long dp[MAXN];
long long fact[MAXW * 2];

long long fastPow(long long x, long long y) {
    long long res = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if (y & (1LL << i)) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
    }
    return res;
}

inline long long inverse(long long x) {
    return fastPow(x, MOD - 2);
}

inline long long combine(long long n, long long m) {
    return fact[n] * inverse(fact[m] * fact[n - m] % MOD) % MOD;
}

inline long long ways(long long r, long long c) {
    if (c < 0) {
        return 0;
    }
    return combine(r + c, r);
}

int main() {
    scanf("%d%d%d", &h, &w, &n);
    fact[0] = 1;
    for (int i = 1; i <= (h + w); ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &point[i].x, &point[i].y);
    }
    point[n] = {h, w};
    sort(point, point + n + 1);
    for (int i = 0; i <= n; ++i) {
        dp[i] = ways(point[i].x - 1, point[i].y - 1);
        for (int j = 0; j < i; ++j) {
            (dp[i] += MOD - dp[j] * ways(point[i].x - point[j].x, point[i].y - point[j].y) % MOD) %= MOD;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
