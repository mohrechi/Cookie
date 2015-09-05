#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;

int n, k;
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        a[i] = n - i - 1;
    }
    int j = max(1, n - 1);
    while (k--) {
        for (int i = 1; i < j; ++i) {
            if (n - j >= a[i]) {
                cout << n - a[i] << " ";
                a[i] = 0;
            } else {
                a[i] -= n - j;
                cout << j << " ";
            }
        }
        for (int i = j; i <= n; ++i) {
            cout << n << " ";
        }
        cout << endl;
        while (j > 1 && a[j - 1] == 0) {
            --j;
        }
    }
    return 0;
}
