#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150000 + 5;

int n, t[MAXN];

inline bool check(int i) {
    if (i < 1 || i >= n) {
        return true;
    }
    return (i & 1) ? t[i] < t[i + 1] : t[i] > t[i + 1];
}

int main() {
    scanf("%d", &n);
    vector<int> bads;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t[i]);
        if (i > 1) {
            if (i & 1) {
                if (t[i] >= t[i - 1]) {
                    bads.push_back(i - 1);
                }
            } else {
                if (t[i] <= t[i - 1]) {
                    bads.push_back(i - 1);
                }
            }
        }
    }
    if ((int)bads.size() > 4) {
        puts("0");
    } else {
        set<pair<int, int>> idx;
        for (auto a : bads) {
            for (int i = a - 1; i <= a + 1; ++i) {
                if (i < 1 || i > n) {
                    continue;
                }
                for (int j = 1; j <= n; ++j) {
                    if (i == j) {
                        continue;
                    }
                    swap(t[i], t[j]);
                    bool flag = true;
                    for (auto b : bads) {
                        for (int k = b - 1; k <= b + 1; ++k) {
                            if (!check(k)) {
                                flag = false;
                            }
                        }
                    }
                    for (int k = i - 1; k <= i + 1; ++k) {
                        if (!check(k)) {
                            flag = false;
                        }
                    }
                    for (int k = j - 1; k <= j + 1; ++k) {
                        if (!check(k)) {
                            flag = false;
                        }
                    }
                    if (flag) {
                        if (i < j) {
                            idx.insert({i, j});
                        } else {
                            idx.insert({j, i});
                        }
                    }
                    swap(t[i], t[j]);
                }
            }
        }
        printf("%d\n", idx.size());
    }
    return 0;
}
