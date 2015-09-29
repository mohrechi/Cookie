#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 25;
const int MAXA = 100000 + 5;
const int MOD = 1000000007;

int fib[MAXN], rev[MAXA];
int num[MAXN];

int main() {
    int n, a;
    memset(rev, -1, sizeof(rev));
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
        rev[fib[i]] = i;
    }
    scanf("%d", &n);
    memset(num, 0, sizeof(num));
    long long ans = 0;
    while (n--) {
        scanf("%d", &a);
        if (a == 1) {
            (num[1] += num[0]) %= MOD;
            ++num[0];
        } else {
            int idx = rev[a];
            if (idx != -1) {
                (num[idx] += num[idx - 1]) %= MOD;
            }
        }
    }
    for (int i = 0; i < MAXN; ++i) {
        ans += num[i];
    }
    cout << ans % MOD << endl;
    return 0;
}
