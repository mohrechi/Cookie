#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
const int MAXK = 26 + 5;

int n, k;
char s[MAXN];
int dp[2][MAXK];
int last[MAXN][MAXK];

int main() {
    while (cin >> n >> k) {
        cin >> s;
        memset(dp, 0, sizeof(dp));
        int curr = 0;
        int prev = 1;
        for (int i = 0; s[i]; ++i) {
            swap(curr, prev);
            for (int j = 0; j < k; ++j) {
                dp[curr][j] = MAXN;
                for (int l = 0; l < k; ++l) {
                    if (j != l) {
                        int val = dp[prev][l] + (s[i] - 'A' != j);
                        if (val < dp[curr][j]) {
                            last[i][j] = l;
                            dp[curr][j] = val;
                        }
                    }
                }
            }
        }
        int ans = MAXN;
        int lastColor;
        for (int i = 0; i < k; ++i) {
            if (dp[curr][i] < ans) {
                ans = dp[curr][i];
                lastColor = i;
            }
        }
        cout << ans << endl;
        for (int i = n - 1; i >= 0; --i) {
            s[i] = lastColor + 'A';
            lastColor = last[i][lastColor];
        }
        cout << s << endl;
    }
    return 0;
}
