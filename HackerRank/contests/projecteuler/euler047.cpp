#include <bits/stdc++.h>
using namespace std;
const int MAXP = 2e3 + 10;
const int MAXN = 2e6 + 10;

bool isPrime[MAXP];
int primes[MAXP], primeNum;

void initPrimes() {
    memset(isPrime, true, sizeof(isPrime));
    primes[0] = 2;
    primeNum = 1;
    for (int i = 3; i < MAXP; i += 2) {
        if (isPrime[i]) {
            primes[primeNum++] = i;
            int inc = i << 1;
            for (int j = i + inc; j < MAXP; j += inc) {
                isPrime[j] = false;
            }
        }
    }
}

int factors[MAXN];

void initFactors() {
    for (int i = 2; i < MAXN; ++i) {
        int t = i;
        for (int j = 0; j < primeNum && primes[j] <= t; ++j) {
            if (t % primes[j] == 0) {
                ++factors[i];
                while (t % primes[j] == 0) {
                    t /= primes[j];
                }
            }
        }
        if (t != 1) {
            ++factors[i];
        }
    }
}

int main() {
    int N, K;
    initPrimes();
    initFactors();
    cin >> N >> K;
    for (int i = 2; i <= N; ++i) {
        bool flag = true;
        for (int j = 0; j < K; ++j) {
            if (factors[i + j] != K) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("%d\n", i);
        }
    }
    return 0;
}
