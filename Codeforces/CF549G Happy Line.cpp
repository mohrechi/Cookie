#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;

int n;
struct Node {
    int a, idx;
    inline int len() const {
        return a + idx;
    }
    bool operator <(const Node &node) const {
        return len() < node.len();
    }
} node[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &node[i].a);
        node[i].idx = i;
    }
    sort (node, node + n);
    bool valid = true;
    for (int i = 1; i < n; ++i) {
        if (node[i - 1].len() == node[i].len()) {
            valid = false;
            break;
        }
    }
    for (int i = 0; i < n && valid; ++i) {
        node[i].a -= i - node[i].idx;
        if (node[i].a < 0) {
            valid = false;
        }
    }
    if (valid) {
        for (int i = 0; i < n; ++i) {
            printf("%d ", node[i].a);
        }
        putchar('\n');
    } else {
        puts(":(");
    }
    return 0;
}
