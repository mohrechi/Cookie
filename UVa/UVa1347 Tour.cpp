#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int n;
double x[MAXN], y[MAXN];

inline double dist(int i, int j) {
    double a = x[i] - x[j];
    double b = y[i] - y[j];
    return sqrt(a * a + b * b);
}

double dp[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> x[i] >> y[i];
        }
        dp[2][1] = dist(1, 2);
        for (int i = 3; i <= n; ++i) {
            dp[i][i - 1] = 1e300;
            for (int j = 1; j < i - 1; ++j) {
                dp[i][j] = dp[i - 1][j] + dist(i, i - 1);
                dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + dist(i, j));
            }
        }
        double minDist = 1e300;
        for (int j = 1; j < n; ++j) {
            minDist = min(minDist, dp[n][j] + dist(n, j));
        }
        cout << setprecision(2) << fixed << minDist << endl;
    }
    return 0;
}
