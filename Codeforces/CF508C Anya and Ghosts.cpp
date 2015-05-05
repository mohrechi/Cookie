#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int m, t, r;
    int w[610];
    while (cin >> m >> t >> r) {
        vector<bool> light(610, false);
        vector<int> num(610, 0);
        for (int i = 0; i < m; ++i) {
            cin >> w[i];
        }
        sort(w, w + m);
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if (num[w[i]] < r) {
                for (int j = 1; j <= t; ++j) {
                    if (!light[w[i] - j + 300]) {
                        light[w[i] - j + 300] = true;
                        ++ans;
                        for (int k = i; k < m; ++k) {
                            if (w[k] > w[i] - j + t) {
                                break;
                            }
                            ++num[w[k]];
                        }
                        if (num[w[i]] >= r) {
                            break;
                        }
                    }
                }
            }
            if (num[w[i]] < r) {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
