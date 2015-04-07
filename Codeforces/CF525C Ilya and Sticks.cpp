#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> l(n);
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
        }
        sort(l.begin(), l.end());
        int first = 0;
        long long ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (l[i] == l[i - 1] || l[i] - 1 == l[i - 1]) {
                if (first == 0) {
                    first = l[i - 1];
                    --i;
                } else {
                    ans += 1LL * first * l[i - 1];
                    --i;
                    first = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
