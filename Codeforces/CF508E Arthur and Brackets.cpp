#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600 + 10;

int n;
int l[MAXN], r[MAXN];
int pos[MAXN];

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        bool possible = true;
        string ans;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            pos[i] = ans.length();
            stk.push(i);
            ans += '(';
            while (not stk.empty()) {
                int t = stk.top();
                if (pos[t] + l[t] <= ans.length()) {
                    if (pos[t] + r[t] < ans.length()) {
                        possible = false;
                        break;
                    }
                    ans += ')';
                    stk.pop();
                } else {
                    break;
                }
            }
        }
        if (not stk.empty()) {
            possible = false;
        }
        if (possible) {
            cout << ans << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
