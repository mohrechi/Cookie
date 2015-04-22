#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

long long d[MAXN];

int main() {
    int n;
    long long A;
    while (cin >> n >> A) {
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
            total += d[i];
        }
        for (int i = 0; i < n; ++i) {
            long long lower = A - n + 1;
            long long upper = A - total + d[i];
            long long b = 0;
            if (lower < d[i]) {
                b += d[i] - lower;
            }
            if (upper > 1) {
                b += upper - 1;
            }
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
