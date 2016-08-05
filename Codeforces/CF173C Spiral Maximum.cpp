#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 5;

int n, m;
int sum[MAXN][MAXN];
int ans = 0x80000000;

inline int getSum(int top, int left, int bottom, int right) {
    --top, --left;
    return sum[bottom][right] - sum[top][right] - sum[bottom][left] + sum[top][left];
}

inline int getVal(int row, int col) {
    return getSum(row, col, row, col);
}

inline bool checkSpiral(int row, int col, int k) {
    return 1 <= row - k && row + k <= n && 1 <= col - k && col + k <= m;
}

void calcSpiral(int row, int col) {
    int spiralSum = getSum(row - 1, col - 1, row + 1, col + 1) -
                    getSum(row, col - 1, row, col);
    ans = max(ans, spiralSum);
    for (int k = 2; checkSpiral(row, col, k); ++k) {
        if (k & 1) {
            spiralSum += getSum(row - k, col - k, row + k, col + k) -
                         getSum(row - k + 1, col - k + 1, row + k - 1, col + k - 1) +
                         getVal(row - k + 2, col - k + 1) -
                         getVal(row - k + 1, col - k);
            ans = max(ans, spiralSum);
        } else {
            int reverseSum = getSum(row - k, col - k, row + k, col + k) -
                             getVal(row - k + 1, col - k) -
                             spiralSum;
            ans = max(ans, reverseSum);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> sum[i][j];
            sum[i][j] += sum[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    for (int i = 2; i < n; ++i) {
        for (int j = 2; j < m; ++j) {
            calcSpiral(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}
