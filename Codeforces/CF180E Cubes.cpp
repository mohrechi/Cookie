#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

map<int, int> last;
vector<pair<int, int>> intervals[MAXN];

int main() {
    int n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0, a; i < n; ++i) {
        cin >> a;
        if (last.find(a) == last.end() or last[a] != i - 1) {
            intervals[a].push_back({i, i});
        } else {
            intervals[a][intervals[a].size() - 1].second = i;
        }
        last[a] = i;
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int l = 0, r = 0;
        n = intervals[i].size();
        if (n == 0) {
            continue;
        }
        int num = intervals[i][0].second - intervals[i][0].first + 1;
        int skip = 0;
        ans = max(ans, num);
        while (true) {
            if (r < n - 1) {
                skip += intervals[i][r + 1].first - intervals[i][r].second - 1;
                ++r;
                num += intervals[i][r].second - intervals[i][r].first + 1;
            }
            while (skip > k) {
                skip -= intervals[i][l + 1].first - intervals[i][l].second - 1;
                num -= intervals[i][l].second - intervals[i][l].first + 1;
                ++l;
            }
            ans = max(ans, num);
            if (r == n - 1) {
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
