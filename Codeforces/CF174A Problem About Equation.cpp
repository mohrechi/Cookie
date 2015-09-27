#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[100], b;
    cin >> n >> b;
    int sum = 0, maxA = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        maxA = max(maxA, a[i]);
    }
    if (b < maxA * n - sum) {
        cout << -1 << endl;
    } else {
        double ave = 1.0 * (b - maxA * n + sum) / n;
        for (int i = 0; i < n; ++i) {
            printf("%.8f\n", ave + maxA - a[i]);
        }
    }
    return 0;
}
