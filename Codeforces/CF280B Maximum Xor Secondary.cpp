#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, s[MAXN], stk[MAXN];

int solve() {
    int top = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        while (top and stk[top - 1] < s[i]) {
            --top;
        }
        if (top) {
            ans = max(ans, stk[top - 1] ^ s[i]);
        }
        stk[top++] = s[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int ans = solve();
    reverse(s, s + n);
    ans = max(ans, solve());
    cout << ans << endl;
    return 0;
}
