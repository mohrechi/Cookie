#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a;
    string s;
    while (cin >> s) {
        n = s.length();
        vector<bool> v(n, false);
        cin >> m;
        while (m--) {
            cin >> a;
            v[a - 1] = v[a - 1] ^ true;
            v[n - a] = v[n - a] ^ true;
        }
        bool rev = false;
        for (int i = 0; i < n / 2; ++i) {
            rev ^= v[i];
            if (rev) {
                swap(s[i], s[n - i - 1]);
            }
        }
        cout << s << endl;
    }
    return 0;
}
