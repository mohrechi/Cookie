#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;

double num[MAXN][MAXN];

int main() {
    int n, t;
    double p;
    while (cin >> n >> p >> t) {
        num[0][0] = 1.0;
        for (int i = 1; i <= t; ++i) {
            for (int j = 0; j <= i; ++j) {
                num[i][j] = num[i - 1][j] * (1.0 - p);
                if (j) {
                    num[i][j] += num[i - 1][j - 1] * p;
                }
            }
        }
        double ans = 0.0;
        for (int j = 1; j <= t; ++j) {
            ans += min(j, n) * num[t][j];
        }
        cout.precision(8);
        cout << fixed << ans << endl;
    }
    return 0;
}
