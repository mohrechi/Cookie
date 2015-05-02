#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;

int main() {
    ios::sync_with_stdio(false);
    int n, k, p, x, y;
    int a[MAXN + 10];
    while (cin >> n >> k >> p >> x >> y) {
        int cnt = 0, sum = 0;
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            if (a[i] >= y) {
                ++cnt;
            }
            sum += a[i];
        }
        bool possible = true;
        for (int i = k; i < n; ++i) {
            if (cnt <= n / 2) {
                a[i] = y;
                ++cnt;
                sum += a[i];
            } else {
                a[i] = 1;
                ++sum;
            }
        }
        if (sum > x || (y != 1 && cnt <= n / 2)) {
            possible = false;
        }
        if (possible) {
            for (int i = k; i < n; ++i) {
                cout << a[i] << ' ';
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
