#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int main() {
    long long n, m;
    cin >> n >> m;
    int a[MAXN], l = 1, r = n;
    --m;
    for (int i = n - 2; i >= 0; --i) {
        if (m >= (1LL << i)) {
            a[r--] = n - i - 1;
            m -= 1LL << i;
        } else {
            a[l++] = n - i - 1;
        }
    }
    a[r] = n;
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
