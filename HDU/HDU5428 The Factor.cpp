#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 5;
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

int main() {
    int T, n, a;
    scanf("%d", &T);
    initPrime();
    while (T--) {
        multiset<int, greater<int> > s;
        scanf("%d", &n);
        while (n--) {
            scanf("%d", &a);
            for (int i = 0; i < primeNum && prime[i] * prime[i] <= a; ++i) {
                while (a % prime[i] == 0) {
                    a /= prime[i];
                    s.insert(prime[i]);
                    if (s.size() > 2) {
                        s.erase(s.begin());
                    }
                }
            }
            if (a > 1) {
                s.insert(a);
                if (s.size() > 2) {
                    s.erase(s.begin());
                }
            }
        }
        if (s.size() < 2) {
            puts("-1");
        } else {
            long long b = *s.begin();
            long long c = *(++s.begin());
            printf("%I64d\n", b * c);
        }
    }
    return 0;
}
