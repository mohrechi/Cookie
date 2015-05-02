#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n;
struct Node {
    int index;
    int value;
    bool operator <(const Node &node) const {
        if (value == node.value) {
            return index < node.index;
        }
        return value < node.value;
    }
} node[MAXN];

int bits[MAXN];

inline int lowbit(int x) {
    return x & (-x);
}

void update(int x) {
    int t = x;
    while (t <= n) {
        ++bits[t];
        t += lowbit(t);
    }
}

int query(int x) {
    int sum = 0;
    int t = x;
    while (t) {
        sum += bits[t];
        t -= lowbit(t);
    }
    return sum;
}

int ans[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        node[i].index = i + 1;
        cin >> node[i].value;
    }
    sort(node, node + n);
    for (int i = 0; i < n; ++i) {
        int v = node[i].index;
        for (int k = 1; k < n && k * (v - 1) + 2 <= n; ++k) {
            int l = k * (v - 1) + 2;
            int r = min(n, k * v + 1);
            ans[k] += query(r) - query(l - 1);
        }
        update(v);
    }
    for (int i = 1; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
