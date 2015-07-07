#include <bits/stdc++.h>
using namespace std;
const int MAXM = 4e5 + 10;

long long sum[MAXM];

int main() {
    int T, M;
    for (int m = 2; m <= 1000; ++m) {
        for (int n = 1; n < m; ++n) {
            if (__gcd(m, n) != 1 or (m - n) % 2 == 0) {
                continue;
            }
            int a = m * m - n * n;
            int b = 2 * m * n;
            int c = m * m + n * n;
            if (a > b) {
                swap(a, b);
            }
            int ka = a, kb = b, kc = c;
            while (ka < MAXM) {
                int t = min(ka, kb / 2) - (kb - ka - 1);
                if (t > 0) {
                    sum[ka] += t;
                }
                if (kb < MAXM) {
                    sum[kb] += min((ka - 1), ka / 2);
                }
                ka += a;
                kb += b;
                kc += c;
            }
        }
    }
    for (int i = 1; i < MAXM; ++i) {
        sum[i] += sum[i - 1];
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &M);
        printf("%lld\n", sum[M]);
    }
    return 0;
}
