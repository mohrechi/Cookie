#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    vector<pair<int, int>> vs;
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> a >> b;
        vs.push_back({a, b});
    }
    sort(vs.begin(), vs.end());
    int last = 0;
    for (auto v : vs) {
        if (min(v.first, v.second) >= last) {
            last = min(v.first, v.second);
        } else {
            last = max(v.first, v.second);
        }
    }
    cout << last << endl;;
}
