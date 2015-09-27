#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    while (cin >> n) {
        int dp[2][4] = {1, 0, 0, 0};
        int curr = 0, prev = 1;
        while (n--) {
            swap(curr, prev);
            for (int i = 0; i < 4; ++i) {
                dp[curr][i] = 0;
                for (int j = 0; j < 4; ++j) {
                    if (i != j) {
                        dp[curr][i] += dp[prev][j];
                        if (dp[curr][i] >= MOD) {
                            dp[curr][i] -= MOD;
                        }
                    }
                }
            }
        }
        cout << dp[curr][0] << endl;
    }
    return 0;
}
