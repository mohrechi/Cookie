#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    while (cin >> n >> m >> k) {
        int a, b;
        map<int, int> pos;
        map<int, int> index;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            pos[a] = i;
            index[i] = a;
        }
        long long ans = 0;
        while (m--) {
            cin >> b;
            ans += pos[b] / k + 1;
            if (pos[b]) {
                int prev = index[pos[b] - 1];
                swap(pos[b], pos[prev]);
                index[pos[b]] = b;
                index[pos[prev]] = prev;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
