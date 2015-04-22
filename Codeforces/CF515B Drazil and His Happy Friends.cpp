#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

int main() {
    int n, m, b, g, x, y;
    bool h[MAXN];
    while (cin >> n >> m) {
        int c = gcd(n, m);
        memset(h, false, sizeof(h));
        cin >> b;
        for (int i = 0; i < b; ++i) {
            cin >> x;
            h[x % c] = true;
        }
        cin >> g;
        for (int j = 0; j < g; ++j) {
            cin >> y;
            h[y % c] = true;
        }
        bool happy = true;
        for (int i = 0; i < c; ++i) {
            if (!h[i]) {
                happy = false;
                break;
            }
        }
        cout << (happy ? "Yes" : "No") << endl;
    }
    return 0;
}
