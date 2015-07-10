#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

int n, m, k, a[MAXN];

int main() {
    cin >> n >> k;
    m = n / k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int num = 0;
        for (int j = i; j < n; j += k) {
            num += a[j] == 1;
        }
        ans += min(num, m - num);
    }
    cout << ans << endl;
    return 0;
}
