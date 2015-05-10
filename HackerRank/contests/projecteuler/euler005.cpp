#include <bits/stdc++.h>
using namespace std;
const int MAXN = 41;

bool isPrime[MAXN];

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 4; i < MAXN; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXN; i += 2) {
        int inc = i << 1;
        for (int j = i + inc; j < MAXN; j += inc) {
            isPrime[j] = false;
        }
    }
}

int factor[MAXN];
long long ans[MAXN];

int main() {
    int T, N;
    initPrime();
    for (int i = 1; i < MAXN; ++i) {
        int t = i;
        for (int j = 2; j < MAXN; ++j) {
            if (isPrime[j]) {
                int cnt = 0;
                while (t % j == 0) {
                    t /= j;
                    ++cnt;
                }
                factor[j] = max(factor[j], cnt);
            }
        }
        ans[i] = 1;
        for (int j = 2; j < MAXN; ++j) {
            for (int k = 0; k < factor[j]; ++k) {
                ans[i] *= j;
            }
        }
    }
    cin >> T;
    while (T--) {
        cin >> N;
        cout << ans[N] << endl;
    }
    return 0;
}
