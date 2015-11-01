#include <bits/stdc++.h>
using namespace std;
const int MAXN = 31700;

bool isPrime[MAXN];
int prime[MAXN], primeNum;

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (isPrime[i]) {
            prime[primeNum++] = i;
            for (int j = i + i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

bool checkPrime(int x) {
    if (x < MAXN) {
        return isPrime[x];
    }
    for (int i = 0; i < primeNum && prime[i] * prime[i] <= x; ++i) {
        if (x % prime[i] == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    initPrime();
    cin >> n;
    int big = n;
    while (!checkPrime(big)) {
        big -= 2;
    }
    if (big == n) {
        cout << 1 << endl;
        cout << n << endl;
    } else {
        int rem = n - big;
        if (rem == 2) {
            cout << 2 << endl;
            cout << 2 << " " << big << endl;
        } else {
            for (int i = 0; i < primeNum; ++i) {
                if (checkPrime(rem - prime[i])) {
                    cout << 3 << endl;
                    cout << prime[i] << " " << rem - prime[i] << " " << big << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
