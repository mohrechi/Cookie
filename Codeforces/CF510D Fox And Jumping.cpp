#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;

int n;
int l[MAXN], c[MAXN];

map<int, int> minCost;

inline void tryAdd(const int &num, const int &cost) {
    if (minCost.find(num) == minCost.end() || minCost[num] > cost) {
        minCost[num] = cost;
    }
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> l[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> c[i];
        }
        minCost.clear();
        for (int i = 1; i <= n; ++i) {
            for (auto cost : minCost) {
                int g = __gcd(cost.first, l[i]);
                tryAdd(g, cost.second + c[i]);
            }
            tryAdd(l[i], c[i]);
        }
        if (minCost.find(1) == minCost.end()) {
            cout << -1 << endl;
        } else {
            cout << minCost[1] << endl;
        }
    }
    return 0;
}
