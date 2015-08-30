#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXP = 1e5 + 5;

bool isPrime[MAXP];
int prime[MAXP], primeNum;

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i < MAXP; ++i) {
        if (isPrime[i]) {
            prime[primeNum++] = i;
            for (int j = i + i; j < MAXP; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int n, a[MAXN];

bool isDiff(const map<int, int> &a, const map<int, int> &b) {
    for (auto f : a) {
        if (f.first != 2 && f.first != 3) {
            auto it = b.find(f.first);
            if (it == b.end()) {
                return true;
            }
            if (it->second != f.second) {
                return true;
            }
        }
    }
    return false;
}

bool operator !=(const map<int, int> &a, const map<int, int> &b) {
    return isDiff(a, b) || isDiff(b, a);
}

map<int, int> decompose(int x) {
    map<int, int> factors;
    for (int i = 0; i < primeNum && prime[i] <= x; ++i) {
        if (x % prime[i] == 0) {
            int cnt = 0;
            while (x % prime[i] == 0) {
                x /= prime[i];
                ++cnt;
            }
            factors[prime[i]] = cnt;
        }
    }
    if (x > 1) {
        factors[x] = 1;
    }
    return factors;
}

int main() {
    initPrime();
    scanf("%d%d", &n, &a[0]);
    auto base = decompose(a[0]);
    set<int> visit;
    visit.insert(a[0]);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &a[i]);
        if (visit.find(a[i]) != visit.end()) {
            continue;
        }
        visit.insert(a[i]);
        if (base != decompose(a[i])) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
