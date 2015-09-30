#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int rating[MAXN];
int dp[MAXN];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &rating[i]);
    }
    int inc = 1;
    for (int i = 1; i < n; ++i) {
        if (rating[i] > rating[i - 1]) {
            dp[i] = ++inc;
        } else {
            dp[i] = inc = 1;
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (rating[i] > rating[i + 1]) {
            dp[i] = max(dp[i], ++inc);
        } else {
            dp[i] = max(dp[i], inc = 1);
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += dp[i];
    }
    cout << sum << endl;
    return 0;
}
