#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

bool isPrime[MAXN];
int prime[MAXN], primeNum;

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
    for (int i = 2; i < MAXN; ++i) {
        if (isPrime[i]) {
            prime[primeNum++] = i;
        }
    }
}

int main() {
    int T;
    long long N;
    initPrime();
    cin >> T;
    while (T--) {
        cin >> N;
        long long ans = 1;
        for (int i = 0; i < primeNum && prime[i] <= N; ++i) {
            while (N % prime[i] == 0) {
                N /= prime[i];
                ans = max(ans, (long long)prime[i]);
            }
        }
        ans = max(ans, N);
        cout << ans << endl;
    }
    return 0;
}
