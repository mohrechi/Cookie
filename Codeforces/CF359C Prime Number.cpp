#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, x;
long long a[MAXN];

long long powMod(long long x, long long y) {
    long long ret = 1;
    for (int i = 0; (1LL << i) <= y; ++i) {
        if ((1LL << i) & y) {
            (ret *= x) %= MOD;
        }
        (x *= x) %= MOD;
    }
    return ret;
}

int main() {
    long long total = 0;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        scanf("%I64d", &a[i]);
        total += a[i];
    }
    for (int i = 0; i < n; ++i) {
        a[i] = total - a[i];
    }
    sort(a, a + n);
    int left = 0, cnt = 0;
    long long sum = 0;
    while (true) {
        if (a[left] == 0) {
            for (int i = left; i <= n; ++i) {
                if (i == n) {
                    left = n;
                    break;
                }
                if (a[i] != 0) {
                    left = i;
                    break;
                } else {
                    ++cnt;
                }
            }
            if (left == n) {
                while (cnt % x == 0) {
                    ++sum;
                    cnt /= x;
                }
                break;
            }
        }
        if (cnt % x) {
            break;
        }
        if (cnt) {
            cnt /= x;
            ++sum;
            for (int i = n - 1; i >= left; --i) {
                --a[i];
            }
        } else {
            sum += a[left];
            for (int i = n - 1; i >= left; --i) {
                a[i] -= a[left];
            }
        }
    }
    sum = min(sum, total);
    cout << powMod(x, sum) << endl;
    return 0;
}
