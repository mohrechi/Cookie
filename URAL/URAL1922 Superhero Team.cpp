#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;

struct Node {
    int index;
    int value;
    bool operator <(const Node& node) const {
        if (value == node.value) {
            return index < node.index;
        }
        return value < node.value;
    }
} a[MAXN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        a[i].index = i;
        scanf("%d", &a[i].value);
    }
    sort(a + 1, a + 1 + n);
    a[n + 1].value = 0x7fffffff;
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        if (i >= a[i].value && i + 1 < a[i + 1].value) {
            ++num;
        }
    }
    printf("%d\n", num);
    for (int i = 1; i <= n; ++i) {
        if (i >= a[i].value && i + 1 < a[i + 1].value) {
            printf("%d", i);
            for (int j = 1; j <= i; ++j) {
                printf(" %d", a[j].index);
            }
            printf("\n");
        }
    }
    return 0;
}
