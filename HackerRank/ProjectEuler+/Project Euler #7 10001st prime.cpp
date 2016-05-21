#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

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
            prime[++primeNum] = i;
        }
    }
}

int main() {
    int T, N;
    initPrime();
    cin >> T;
    while (T--) {
        cin >> N;
        cout << prime[N] << endl;
    }
    return 0;
}
