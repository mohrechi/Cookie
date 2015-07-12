#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;

int n, m;
int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
pair<int, int> last[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    for (int j = 1; j <= m; ++j) {
        cin >> b[j];
    }
    long long ans = 0;
    pair<int, int> idx;
    for (int i = 1; i <= n; ++i) {
        int maxVal = 0;
        pair<int, int> maxIdx = {i - 1, 0};
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = dp[i - 1][j];
            last[i][j] = {i - 1, j};
            if (a[i] > b[j] and maxVal < dp[i - 1][j]) {
                maxVal = dp[i - 1][j];
                maxIdx = {i - 1, j};
            }
            if (a[i] == b[j]) {
                dp[i][j] = maxVal + 1;
                last[i][j] = maxIdx;
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                    idx = {i, j};
                }
            }
        }
    }
    cout << ans << endl;
    stack<int> vals;
    while (idx.second != 0) {
        if (vals.size() == 0 or vals.top() != b[idx.second]) {
            vals.push(b[idx.second]);
        }
        idx = last[idx.first][idx.second];
    }
    while (vals.size()) {
        cout << vals.top() << " ";
        vals.pop();
    }
    cout << endl;
    return 0;
}
