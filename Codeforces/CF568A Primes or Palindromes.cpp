#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7;

bool isPrime[MAXN];
int primeSum[MAXN];
int palinSum[MAXN];

bool isPalin(int x) {
    int tx = x, y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return tx == y;
}

void init() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    palinSum[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        palinSum[i] += palinSum[i - 1] + isPalin(i);
        primeSum[i] += primeSum[i - 1];
        if (isPrime[i]) {
            ++primeSum[i];
            for (int j = i + i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int p, q;
    init();
    while (cin >> p >> q) {
        int num = 0;
        for (int i = 1; i < MAXN; ++i) {
            if (1LL * q * primeSum[i] <= 1LL * p * palinSum[i]) {
                num = i;
            }
        }
        cout << num << endl;
    }
    return 0;
}
