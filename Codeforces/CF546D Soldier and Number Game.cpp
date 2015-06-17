#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000000 + 1;
const int MAXP = 348513 + 1;

bool notPrime[MAXN];
int prime[MAXP], primeNum;

void initPrime() {
    prime[0] = 2;
    primeNum = 1;
    for (int i = 3; i < MAXN; i += 2) {
        if (not notPrime[i]) {
            prime[primeNum++] = i;
            int inc = i << 1;
            for (int j = i + inc; j < MAXN; j += inc) {
                notPrime[j] = true;
            }
        }
    }
}

int factor[MAXN];

void initFactor() {
    factor[1] = 1;
    for (int i = 0; i < primeNum; ++i) {
        for (long long j = prime[i]; j < MAXN; j *= prime[i]) {
            for (int k = j; k < MAXN; k += j) {
                ++factor[k];
            }
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        factor[i] += factor[i - 1];
    }
}

int main() {
    int t, a, b;
    initPrime();
    initFactor();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", factor[a] - factor[b]);
    }
    return 0;
}
