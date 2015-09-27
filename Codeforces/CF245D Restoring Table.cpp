#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int n, a[MAXN], b;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b;
            if (i == j) {
                continue;
            }
            a[i] |= b;
            a[j] |= b;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
