#include <bits/stdc++.h>
using namespace std;

struct Node {
    int index, val;
    bool operator <(const Node &node) const {
        return val < node.val;
    }
} node[101];

int main() {
    int n, k, a;
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            node[i] = {i, a};
        }
        sort(node + 1, node + 1 + n);
        int sum = 0;
        vector<int> ans;
        for (int i = 1; i <= n; ++i) {
            sum += node[i].val;
            if (sum > k) {
                break;
            }
            ans.push_back(node[i].index);
        }
        cout << ans.size() << endl;
        for (auto index : ans) {
            cout << index << ' ';
        }
        cout << endl;
    }
    return 0;
}
