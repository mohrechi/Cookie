#include <bits/stdc++.h>
using namespace std;

int an, bn;
string a, b;

int main() {
    cin >> an >> bn;
    cin >> a >> b;
    int al = a.length(), bl = b.length();
    vector<pair<int, int>> next(b.size());
    for (int j = 0; j < bl; ++j) {
        int idx = j;
        for (int i = 0; i < al; ++i) {
            if (b[idx] == a[i]) {
                ++idx;
                if (idx == bl) {
                    ++next[j].second;
                    idx = 0;
                }
            }
        }
        next[j].first = idx;
    }
    long long ans = 0;
    int idx = 0;
    for (int i = 0; i < an; ++i) {
        ans += next[idx].second;
        idx = next[idx].first;
    }
    cout << ans / bn << endl;
    return 0;
}
