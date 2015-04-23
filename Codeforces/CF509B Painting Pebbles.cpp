#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int n, k;
int a[MAXN];

int main() {
    while (cin >> n >> k) {
        int minA = 100, maxA = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            minA = min(minA, a[i]);
            maxA = max(maxA, a[i]);
        }
        if (maxA - minA > k) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < a[i]; ++j) {
                    if (j <= minA) {
                        cout << 1 << " ";
                    } else {
                        cout << j - minA + 1 << " ";
                    }
                }
                cout << endl;
            }
        }
    }
    return 0;
}
