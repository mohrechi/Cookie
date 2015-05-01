#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    int d1, h1, d2, h2;
    while (cin >> n >> m) {
        int ans = 0;
        bool possible = true;
        cin >> d1 >> h1;
        ans = max(ans, h1 + (d1 - 1));
        while (--m) {
            cin >> d2 >> h2;
            if (abs(h2 - h1) > d2 - d1) {
                possible = false;
            }
            ans = max(ans, max(h1, h2) + (d2 - d1 - abs(h2 - h1)) / 2);
            d1 = d2;
            h1 = h2;
        }
        ans = max(ans, h1 + (n - d1));
        if (possible) {
            cout << ans << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
