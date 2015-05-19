#include <bits/stdc++.h>
using namespace std;

int poly(int k, int n) {
    switch (k) {
    case 3: return n * (n + 1) / 2;
    case 4: return n * n;
    case 5: return n * (3 * n - 1) / 2;
    case 6: return n * (2 * n - 1);
    case 7: return n * (5 * n - 3) / 2;
    case 8: return n * (3 * n - 2);
    }
    return 0;
}

int T;
int num[10];
map<int, set<int>> vals;
bool visit[10];
int path[10], digi[10];
set<int> ans;

void dfs(int d, int sum) {
    if (d == T) {
        if (path[T - 1] % 100 == path[0] / 100) {
            set<int> t;
            for (int i = 0; i < d; ++i) {
                for (int j = i + 1; j < d; ++j) {
                    if (path[i] == path[j]) {
                        return;
                    }
                }
            }
            ans.insert(sum);
        }
    } else {
        for (int i = 0; i < T; ++i) {
            if (not visit[i]) {
                visit[i] = true;
                for (auto val : vals[num[i]]) {
                    if (d == 0 or path[d - 1] % 100 == val / 100) {
                        path[d] = val;
                        digi[d] = i;
                        dfs(d + 1, sum + val);
                    }
                }
                visit[i] = false;
            }
        }
    }
}

void solve() {
    for (int i = 3; i <= 8; ++i) {
        for (int j = 1; ; ++j) {
            int val = poly(i, j);
            if (val > 9999) {
                break;
            }
            if (val > 999 and val % 100 > 9) {
                vals[i].insert(val);
            }
        }
    }
    dfs(0, 0);
    for (auto a : ans) {
        cout << a << endl;
    }
}

int main() {
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> num[i];
    }
    solve();
    return 0;
}
