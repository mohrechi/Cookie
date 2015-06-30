#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, m;
long long l[MAXN], r[MAXN];
struct Interval {
    int index;
    long long l, r;
    bool operator <(const Interval &inter) const {
        if (r == inter.r) {
            return index < inter.index;
        }
        return r < inter.r;
    }
} interval[MAXN];
struct Bridge {
    int index;
    long long len;
    bool operator <(const Bridge &bridge) const {
        if (len == bridge.len) {
            return index < bridge.index;
        }
        return len < bridge.len;
    }
} bridge[MAXN];
set<Bridge> bridges;
int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        if (i) {
            interval[i] = {i, l[i] - r[i-1], r[i] - l[i-1]};
        }
    }
    sort(interval + 1, interval + n);
    for (int i = 1; i <= m; ++i) {
        bridge[i].index = i;
        cin >> bridge[i].len;
    }
    sort(bridge + 1, bridge + m + 1);
    int maxIdx = 1;
    bool valid = true;
    for (int i = 1; i < n; ++i) {
        while (maxIdx <= m and bridge[maxIdx].len <= interval[i].r) {
            bridges.insert(bridge[maxIdx]);
            ++maxIdx;
        }
        auto it = bridges.upper_bound({0, interval[i].l});
        if (it == bridges.end()) {
            valid = false;
            break;
        } else {
            ans[interval[i].index] = it->index;
            bridges.erase(it);
        }
    }
    if (valid) {
        cout << "Yes" << endl;
        for (int i = 1; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
