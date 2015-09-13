#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 5;

int n, a[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[k]) {
                k = j;
            }
        }
        if (k != i) {
            ans.push_back({i, k});
            swap(a[i], a[k]);
        }
    }
    printf("%d\n", (int)ans.size());
    for (auto a : ans) {
        printf("%d %d\n", a.first, a.second);
    }
    return 0;
}
