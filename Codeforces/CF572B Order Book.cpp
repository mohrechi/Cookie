#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const int MAXS = 50 + 10;

int main() {
    int n, s, p, q;
    char d[2];
    scanf("%d%d", &n, &s);
    map<int, int, greater<int>> buy;
    map<int, int, greater<int>> sell;
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d", d, &p, &q);
        if (d[0] == 'B') {
            buy[p] += q;
        } else {
            sell[p] += q;
        }
    }
    while ((int)sell.size() > s) {
        sell.erase(sell.begin());
    }
    while (sell.size() > 0) {
        auto it = sell.begin();
        printf("S %d %d\n", it->first, it->second);
        sell.erase(it);
    }
    while ((int)buy.size() > s) {
        buy.erase(buy.rbegin()->first);
    }
    while (buy.size() > 0) {
        auto it = buy.begin();
        printf("B %d %d\n", it->first, it->second);
        buy.erase(it);
    }
    return 0;
}
