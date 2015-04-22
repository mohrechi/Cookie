#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5;
const int MAXM = 20;

int n, m;
int a[MAXN], b[MAXM];

int num[MAXM];
char ans[MAXN][MAXM];

set<int> states[MAXM];

int getState(int mask, int num[MAXM]) {
    int res = mask;
    for (int i = 0; i < n; ++i) {
        res = res * MAXN + num[i];
    }
    return res;
}

bool dfs(int j, int lastState = 0) {
    if (j == m) {
        for (int i = 0; i < n; ++i) {
            if (num[i] != a[i]) {
                return false;
            }
        }
        return true;
    }
    if (j) {
        if (states[j].find(lastState) != states[j].end()) {
            return false;
        }
        states[j].insert(lastState);
    }
    int origin[MAXM];
    memcpy(origin, num, sizeof(num));
    for (int k = 0; k < (1 << n); ++k) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (k & (1 << i)) {
                ans[i][j] = '*';
                if (i == 0 || ans[i - 1][j] == '.') {
                    ++cnt;
                }
            } else {
                ans[i][j] = '.';
            }
        }
        if (cnt != b[j]) {
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i][j] == '*') {
                if (j == 0 || ans[i][j - 1] == '.') {
                    ++num[i];
                }
            }
        }
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (num[i] > a[i]) {
                valid = false;
                break;
            }
            if (ans[i][j] == '*') {
                if (a[i] - num[i] > (m - j - 1) / 2) {
                    valid = false;
                    break;
                }
            } else {
                if (a[i] - num[i] > (m - j) / 2) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            if (dfs(j + 1, getState(k, num))) {
                return true;
            }
        }
        memcpy(num, origin, sizeof(origin));
    }
    return false;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        for (int i = 0; i < n; ++i) {
            states[i].clear();
        }
        memset(num, 0, sizeof(num));
        dfs(0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
