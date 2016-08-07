#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150000 + 5;
const int MAXM = 300 + 5;

int n, m;
long long d;
int a[MAXM], b[MAXM], t[MAXM];
long long dp[2][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> t[i];
    }
    int curr = 0, prev = 1;
    for (int i = 1; i <= m; ++i) {
        swap(curr, prev);
        int td = (int)min((long long)n, (t[i] - t[i - 1]) * d);
        int r = 0;
        deque<pair<long long, int>> que;
        for (int x = 1; x <= n; ++x) {
            int xl = max(1, x - td);
            int xr = min(n, x + td);
            while (r < xr) {
                ++r;
                while (!que.empty() && que.back().first <= dp[prev][r]) {
                    que.pop_back();
                }
                que.push_back({dp[prev][r], r});
            }
            while (que.front().second < xl) {
                que.pop_front();
            }
            dp[curr][x] = que.front().first + b[i] - abs(a[i] - x);
        }
    }
    long long ans = dp[curr][1];
    for (int i = 2; i <= n; ++i) {
        ans = max(ans, dp[curr][i]);
    }
    cout << ans << endl;
    return 0;
}
