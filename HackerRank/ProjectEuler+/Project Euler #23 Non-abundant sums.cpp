#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

bool isPrime[MAXN];
int prime[MAXN], primeNum;
bool isAbundant[MAXN];

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

int getSum(int x) {
    int ret = 1;
    int t = x;
    for (int j = 0; j < primeNum and prime[j] <= x; ++j) {
        if (x % prime[j] == 0) {
            int cnt = prime[j];
            while (x % prime[j] == 0) {
                x /= prime[j];
                cnt *= prime[j];
            }
            ret *= (cnt - 1) / (prime[j] - 1);
        }
    }
    if (x > 1) {
        ret *= (1 + x);
    }
    return ret - t;
}

int main() {
    int T, N;
    initPrime();
    for (int i = 1; i < MAXN; ++i) {
        if (getSum(i) > i) {
            isAbundant[i] = true;
        }
    }
    cin >> T;
    while (T--) {
        cin >> N;
        bool flag = false;
        for (int i = 1; i < N; ++i) {
            if (isAbundant[i] and isAbundant[N - i]) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
