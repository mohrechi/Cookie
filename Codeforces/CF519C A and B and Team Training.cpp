#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        int ans = 0;
        for (int i = 0; i <= n; ++i) {
            int num1 = max(0, min(i, m / 2));
            int num2 = max(0, min((n - num1) / 2, m - num1 * 2));
            ans = max(ans, num1 + num2);
        }
        cout << ans << endl;
    }
    return 0;
}
