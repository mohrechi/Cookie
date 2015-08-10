#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, a[MAXN], num[MAXN];

int main() {
    int l;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    set<int> s;
    for (int i = n; i >= 1; --i) {
        s.insert(a[i]);
        num[i] = s.size();
    }
    while (m--) {
        scanf("%d", &l);
        printf("%d\n", num[l]);
    }
    return 0;
}
