#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;

struct Node {
    int idx, val;
};

int main() {
    int n, m;
    Node node;
    list<Node> nodes;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        node.idx = i;
        cin >> node.val;
        nodes.push_back(node);
    }
    while (nodes.size() > 1) {
        Node u = (*nodes.begin());
        nodes.pop_front();
        if (u.val > m) {
            nodes.push_back({u.idx, u.val - m});
        }
    }
    cout << nodes.begin()->idx << endl;
    return 0;
}
