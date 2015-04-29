#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int n, m;
long long w[MAXN][MAXN];
long long k, a[MAXN], b[MAXN];

int main() {
    while (cin >> n >> m) {
        long long maxW = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> w[i][j];
                maxW = max(maxW, w[i][j]);
            }
        }
        bool valid = true;
        a[0] = 0;
        b[0] = w[0][0] - a[0];
        for (int j = 1; j < m; ++j) {
            b[j] = b[j - 1] + w[0][j] - w[0][j - 1];
        }
        for (int i = 1; i < n; ++i) {
            a[i] = w[i][0] - b[0];
        }
        bool hasNonZero = false;
        long long g;
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                long long d = a[i] + b[j] - w[i][j];
                if (d) {
                    if (hasNonZero) {
                        g = __gcd(g, abs(d));
                    } else {
                        g = abs(d);
                        hasNonZero = true;
                    }
                }
            }
        }
        if (!hasNonZero) {
            k = maxW + 1;
        } else {
            k = g;
            for (int i = 0; i < n && valid; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (g <= w[i][j]) {
                        valid = false;
                        break;
                    }
                }
            }
        }
        if (valid) {
            cout << "YES" << endl;
            cout << k << endl;
            for (int i = 0; i < n; ++i) {
                cout << (a[i] % k + k) % k << " ";
            }
            cout << endl;
            for (int j = 0; j < m; ++j) {
                cout << (b[j] % k + k) % k << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
