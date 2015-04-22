#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        vector<vector<int>> type(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> type[i][j];
            }
        }
        int longest = 0;
        vector<int> shoot(m, 0);
        vector<multiset<int, greater<int>>> maxValue(m);
        int left = 0, right = 0;
        while (right != n) {
            while (right < n) {
                int sum = 0;
                for (int j = 0; j < m; ++j) {
                    maxValue[j].insert(type[right][j]);
                    sum += *maxValue[j].begin();
                }
                ++right;
                if (sum <= k) {
                    if (right - left > longest) {
                        longest = right - left;
                        for (int j = 0; j < m; ++j) {
                            shoot[j] = *maxValue[j].begin();
                        }
                    }
                } else {
                    break;
                }
            }
            while (left < right) {
                int sum = 0;
                for (int j = 0; j < m; ++j) {
                    maxValue[j].erase(type[left][j]);
                    sum += *maxValue[j].begin();
                }
                ++left;
                if (sum <= k) {
                    break;
                }
            }
            if (right - left > longest) {
                longest = right - left;
                for (int j = 0; j < m; ++j) {
                    shoot[j] = *maxValue[j].begin();
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            cout << shoot[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
