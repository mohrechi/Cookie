#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, a[MAXN];
int dp[MAXN], top;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    top = 1;
    dp[0] = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] > dp[top - 1]) {
            dp[top++] = a[i];
        } else {
            int l = 0, r = top - 1, pos = top - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (a[i] < dp[mid]) {
                    r = mid - 1;
                    pos = min(pos, mid);
                } else {
                    l = mid + 1;
                }
            }
            dp[pos] = min(dp[pos], a[i]);
        }
    }
    cout << top << endl;
    return 0;
}
