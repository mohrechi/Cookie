#include <bits/stdc++.h>
using namespace std;
const int MAXN = 65000 + 5;

bool isPrime[MAXN];

long long powMod(long long x, long long y, long long mod) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if (y & (1LL << i)) {
            ret = ret * x % mod;
        }
        x = x * x % mod;
    }
    return ret;
}

int main() {
    long long n;
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
    while (cin >> n, n) {
        bool flag = !isPrime[n];
        for (long long a = 2; a < n && flag; ++a) {
            if (powMod(a, n, n) != a) {
                flag = false;
                isPrime[n] = true;
            }
        }
        if (flag) {
            cout << "The number " << n << " is a Carmichael number." << endl;
        } else {
            cout << n << " is normal." << endl;
        }
    }
    return 0;
}
