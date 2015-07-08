#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;

int main() {
    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;
    int x[4] = {1, 1, n, n};
    int y[4] = {1, m, 1, m};
    int ans = INF;
    for (int k = 0; k < 4; ++k) {
        if (abs(x[k] - i) % a or abs(y[k] - j) % b) {
            continue;
        }
        if (i != x[k] and j - b < 1 and j + b > m) {
            continue;
        }
        if (j != y[k] and i - a < 1 and i + a > n) {
            continue;
        }
        int sx = abs(x[k] - i) / a;
        int sy = abs(y[k] - j) / b;
        if ((sx & 1) ^ (sy & 1)) {
            continue;
        }
        ans = min(ans, max(sx, sy));
    }
    if (ans == INF) {
        cout << "Poor Inna and pony!" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
