#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;

double dp[MAXN][MAXN][2];

double get(int w, int b, int order) {
    if (dp[w][b][order] > -0.5) {
        return dp[w][b][order];
    }
    if (w == 0) {
        return dp[w][b][order] = 0.0;
    }
    if (b == 0) {
        return dp[w][b][order] = 1.0;
    }
    double prob = 0.0;
    if (order == 0) {
        prob += (double)w / (w + b);
        prob += (double)b / (w + b) * (1.0 - get(w, b - 1, 1));
    } else {
        prob += (double)w / (w + b);
        prob += (double)b / (w + b) * w / (w + b - 1) * (1.0 - get(w - 1, b - 1, 0));
        if (b >= 2) {
            prob += (double)b / (w + b) * (b - 1) / (w + b - 1) * (1.0 - get(w, b - 2, 0));
        }
    }
    return dp[w][b][order] = prob;
}

int main() {
    int w, b;
    cin >> w >> b;
    for (int i = 0; i <= w; ++i) {
        for (int j = 0; j <= b; ++j) {
            dp[i][j][0] = dp[i][j][1] = -1.0;
        }
    }
    printf("%.10f\n", get(w, b, 0));
    return 0;
}
