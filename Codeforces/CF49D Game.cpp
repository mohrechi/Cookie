#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0;
    string s;
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < (int)s.size(); ++i) {
        cnt += (s[i] & 1) != (i & 1);
    }
    cout << min(cnt, n - cnt) << endl;
    return 0;
}
