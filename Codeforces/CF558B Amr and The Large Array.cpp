#include <bits/stdc++.h>
using namespace std;
const int MAXA = 1e6 + 10;

struct Node {
    int l, r, cnt;
    bool operator <(const Node& node) const {
        if (cnt == node.cnt) {
            return r - l < node.r - node.l;
        }
        return cnt > node.cnt;
    }
} node[MAXA];

int main() {
    int n, a;
    map<int, Node> cnt;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        if (node[a].cnt == 0) {
            node[a] = {i, i, 1};
        } else {
            ++node[a].cnt;
            node[a].r = i;
        }
    }
    sort(node, node + MAXA);
    cout << node[0].l << " " << node[0].r << endl;
    return 0;
}
