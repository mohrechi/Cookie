#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, b;
    bool operator <(const Node &node) const {
        if (a == node.a) {
            return b < node.b;
        }
        return a < node.a;
    }
} node[5];

int main() {
    for (int i = 0; i < 5; ++i) {
        scanf("%d%d", &node[i].a, &node[i].b);
    }
    sort(node, node + 5);
    bool balanced = true;
    for (int i = 1; i < 5; ++i) {
        balanced &= node[i].a > node[i - 1].a;
        balanced &= node[i].b > node[i - 1].b;
    }
    printf("%d\n", balanced);
    return 0;
}
