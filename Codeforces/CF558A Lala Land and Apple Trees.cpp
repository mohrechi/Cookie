#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int n;
struct Tree {
    int x, a;
    bool operator <(const Tree &tree) const {
        return x < tree.x;
    }
} tree[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tree[i].x >> tree[i].a;
    }
    sort(tree, tree + n);
    int leftNum = 0;
    while (leftNum < n and tree[leftNum].x < 0) {
        ++leftNum;
    }
    int rightNum = n - leftNum;
    int takeLeft = min(leftNum, rightNum);
    int takeRight = min(takeLeft + 1, max(leftNum, rightNum));
    if (leftNum > rightNum) {
        swap(takeLeft, takeRight);
    }
    int ans = 0;
    for (int i = leftNum - 1, j = takeLeft; j > 0; --i, --j) {
        ans += tree[i].a;
    }
    for (int i = leftNum, j = takeRight; j > 0; ++i, --j) {
        ans += tree[i].a;
    }
    cout << ans << endl;
    return 0;
}
