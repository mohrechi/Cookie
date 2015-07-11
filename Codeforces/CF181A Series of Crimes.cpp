#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int main() {
    int n, m;
    char s[MAXN][MAXN];
    cin >> n >> m;
    int t = n, b = 1, l = m, r = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '*') {
                t = min(t, i);
                b = max(b, i);
                l = min(l, j);
                r = max(r, j);
            }
        }
    }
    if (s[t][l] == '.') {
        cout << t << " " << l << endl;
    } else if (s[t][r] == '.') {
        cout << t << " " << r << endl;
    } else if (s[b][l] == '.') {
        cout << b << " " << l << endl;
    } else {
        cout << b << " " << r << endl;
    }
    return 0;
}
