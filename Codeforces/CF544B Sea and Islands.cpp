#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        int num = 0;
        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) & 1) {
                    ans[i] += 'S';
                } else {
                    if (num < k) {
                        ++num;
                        ans[i] += 'L';
                    } else {
                        ans[i] += 'S';
                    }
                }
            }
        }
        if (num == k) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                cout << ans[i] << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
