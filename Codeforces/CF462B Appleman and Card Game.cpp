#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, k, cnt[26];
char s[MAXN];

int main() {
    cin >> n >> k >> s;
    for (int i = 0; s[i]; ++i) {
        ++cnt[s[i] - 'A'];
    }
    multiset<int, greater<int>> s;
    for (int i = 0; i < 26; ++i) {
        s.insert(cnt[i]);
    }
    long long ans = 0;
    for (auto v : s) {
        if (v > k) {
            ans += 1LL * k * k;
            break;
        } else {
            ans += 1LL * v * v;
            k -= v;
        }
    }
    cout << ans << endl;
    return 0;
}
