#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200 + 5;

int n, cnt[MAX_N][4];
char op[MAX_N];

inline int getIndex(char ch) {
    if (ch == 'U') {
        return 0;
    }
    if (ch == 'R') {
        return 1;
    }
    return ch == 'D' ? 2 : 3;
}

int main() {
    cin >> n >> (op + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cnt[i][j] = cnt[i - 1][j];
        }
        ++cnt[i][getIndex(op[i])];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (cnt[j][0] - cnt[i][0] == cnt[j][2] - cnt[i][2]) {
                if (cnt[j][1] - cnt[i][1] == cnt[j][3] - cnt[i][3]) {
                    ++ans;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
