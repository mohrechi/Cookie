#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;

int n, T;
double p[MAXN];
int t[MAXN];
double dp[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf%d", &p[i], &t[i]);
        p[i] *= 0.01;
    }
    double ans = 0.0;
    dp[0][0] = 1.0;
    for (int i = 1; i <= n; ++i) {
        double sum = 0.0;
        double npn = pow(1.0 - p[i], t[i]);
        for (int j = 1; j <= T; ++j) {
            sum += dp[i - 1][j - 1];
            if (j > t[i]) {
                sum -= dp[i - 1][j - t[i] - 1] * npn;
            }
            dp[i][j] += sum * p[i];
            if (j >= t[i]) {
                dp[i][j] += dp[i - 1][j - t[i]] * npn;
            }
            sum *= 1.0 - p[i];
            ans += dp[i][j];
        }
    }
    printf("%.8f\n", ans);
    return 0;
}
