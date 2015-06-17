#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5e6 + 10;

int cnt[MAXN];
int sum[MAXN];

void init() {
    for (long long m = 1; m * m < MAXN; ++m) {
        for (long long n = 1; n < m; ++n) {
            if (__gcd(m, n) == 1) {
                if ((m - n) & 1) {
                    long long a = m * m - n * n;
                    long long b = 2 * m * n;
                    long long c = m * m + n * n;
                    long long l = a + b + c;
                    for (long long i = l; i < MAXN; i += l) {
                        ++cnt[i];
                    }
                }
            }
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        sum[i] = sum[i - 1] + (cnt[i] == 1);
    }
}

int main() {
    int T, N;
    ios::sync_with_stdio(false);
    init();
    cin >> T;
    while (T--) {
        cin >> N;
        cout << sum[N] << endl;
    }
    return 0;
}
