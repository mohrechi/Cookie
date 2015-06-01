#include <bits/stdc++.h>
using namespace std;

map<char, set<char>> edges;
struct Degree {
    char ch;
    int num;
    Degree() {
        num = 0;
    }
    bool operator <(const Degree &d) const {
        if (num == d.num) {
            return ch < d.ch;
        }
        return num < d.num;
    }
};
map<char, Degree> cnt;
set<Degree> remain;

int main() {
    int t;
    string s;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> s;
        cnt[s[0]];
        for (int i = 1; i < (int)s.length(); ++i) {
            edges[s[i - 1]].insert(s[i]);
        }
    }
    for (auto edge : edges) {
        for (auto v : edge.second) {
            ++cnt[v].num;
        }
    }
    for (auto it : cnt) {
        cnt[it.first].ch = it.first;
        remain.insert(cnt[it.first]);
    }
    string ans;
    while (remain.size() > 0U) {
        auto first = remain.begin();
        if (first->num != 0) {
            break;
        }
        ans += first->ch;
        remain.erase(first);
        for (auto v : edges[first->ch]) {
            Degree d = cnt[v];
            remain.erase(d);
            d.num -= 1;
            remain.insert(d);
            cnt[v] = d;
        }
    }
    if (remain.size() > 0U) {
        cout << "SMTH WRONG" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
