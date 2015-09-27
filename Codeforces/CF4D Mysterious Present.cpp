#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;

int n, w, h;
struct Envelope {
    int idx, w, h;
    bool operator <(const Envelope &env) const {
        if (w == env.w) {
            return h < env.h;
        }
        return w < env.w;
    }
} env[MAXN];

int dp[MAXN], pre[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> w >> h;
    int m = 0;
    for (int i = 0; i < n; ++i) {
        env[m].idx = i + 1;
        cin >> env[m].w >> env[m].h;
        if (env[m].w > w && env[m].h > h) {
            ++m;
        }
    }
    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }
    sort(env, env + m);
    int pos = 0;
    for (int i = 0; i < m; ++i) {
        dp[i] = 1;
        pre[i] = -1;
        for (int j = 0; j < i; ++j) {
            if (env[i].w > env[j].w && env[i].h > env[j].h) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if (dp[i] > dp[pos]) {
            pos = i;
        }
    }
    cout << dp[pos] << endl;
    n = 0;
    while (pos != -1) {
        dp[n++] = env[pos].idx;
        pos = pre[pos];
    }
    reverse(dp, dp + n);
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}
