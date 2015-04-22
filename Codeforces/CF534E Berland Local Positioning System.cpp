#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXM = 4e5 + 10;

int n, m;
int a[MAXN], b;
int cnt[MAXN];

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= m; ++i) {
            cin >> b;
            ++cnt[b];
            if (b == 1 || b == n) {
                ++cnt[b];
            }
        }
        int maxCnt = 0, minCnt = MAXM;
        for (int i = 1; i <= n; ++i) {
            maxCnt = max(maxCnt, cnt[i]);
            minCnt = min(minCnt, cnt[i]);
        }
        if (maxCnt == minCnt) {
            bool ambiguous = false;
            int diff = a[2] - a[1];
            for (int i = 3; i <= n; ++i) {
                if (a[i] - a[i - 1] != diff) {
                    ambiguous = true;
                    break;
                }
            }
            if (ambiguous) {
                cout << -1 << endl;
            } else {
                cout << (long long)(a[n] - a[1]) * minCnt - diff << endl;
            }
        } else {
            long long ans = 0;
            for (int i = 2; i <= n; ++i) {
                ans += (long long)(a[i] - a[i - 1]) * min(cnt[i], cnt[i - 1]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
