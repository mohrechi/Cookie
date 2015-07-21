#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i * i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (__gcd(i, j) == 1 and (i - j) % 2) {
                ans += n / (i * i + j * j);
            }
        }
    }
    cout << ans;
    return 0;
}
