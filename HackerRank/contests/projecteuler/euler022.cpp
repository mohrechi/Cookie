#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5200;

int main() {
    int N, Q;
    string s;
    ios::sync_with_stdio(false);
    map<string, int> strs;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        strs[s] = 0;
    }
    int index = 0;
    for (auto it = strs.begin(); it != strs.end(); ++it) {
        it->second = ++index;
    }
    cin >> Q;
    while (Q--) {
        long long ans = 0;
        cin >> s;
        for (auto c : s) {
            ans += c - 'A' + 1;
        }
        cout << ans * strs[s] << endl;
    }
    return 0;
}
