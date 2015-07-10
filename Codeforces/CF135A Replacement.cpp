#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    a[n - 1] = a[n - 1] == 1 ? 2 : 1;
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
    return 0;
}
