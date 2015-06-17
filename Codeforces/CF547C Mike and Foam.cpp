#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int a[MAXN], cnt[MAXN];
bool visit[MAXN];

vector<int> f[MAXN];

int main() {
    int n, q, x;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 2; i < MAXN; ++i) {
        if ((int)f[i].size() == 0) {
            for (int j = i; j < MAXN; j += i) {
                f[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    while (q--) {
        cin >> x;
        int m = f[a[x]].size();
        for (int i = 0; i < (1 << m); ++i) {
            int pos = visit[x] ? -1 : 1;
            int val = 1;
            for (int j = 0; j < m; ++j) {
                if ((1 << j) & i) {
                    pos = pos == 1 ? -1 : 1;
                    val *= f[a[x]][j];
                }
            }
            if (visit[x]) {
                cnt[val] -= 1;
                ans += pos * cnt[val];
            } else {
                ans += pos * cnt[val];
                cnt[val] += 1;
            }
        }
        visit[x] = not visit[x];
        cout << ans << endl;
    }
    return 0;
}
