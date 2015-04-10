#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;

struct Node {
    int l, r;
    bool operator <(const Node &node) const {
        if (r == node.r) {
            return l < node.l;
        }
        return r < node.r;
    }
    friend istream& operator >>(istream& in, Node &node) {
        int x, w;
        in >> x >> w;
        node.l = x - w;
        node.r = x + w;
        return in;
    }
} node[MAXN];

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> node[i];
        }
        sort(node, node + n);
        int ans = 1;
        int last = 0;
        for (int i = 1; i < n; ++i) {
            if (node[last].r <= node[i].l) {
                ++ans;
                last = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
