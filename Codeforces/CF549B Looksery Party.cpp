#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int n, a[MAXN];
char s[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> (s[i] + 1);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    while (true) {
        int zeroIdx = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                zeroIdx = i;
                break;
            }
        }
        if (zeroIdx) {
            ans.push_back(zeroIdx);
            for (int i = 1; i <= n; ++i) {
                a[i] -= s[zeroIdx][i] == '1';
            }
        } else {
            break;
        }
    }
    cout << ans.size() << endl;
    for (auto a : ans) {
        cout << a << " ";
    }
    return 0;
}
