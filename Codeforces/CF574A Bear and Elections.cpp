#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int n, a[MAXN];

int main() {
    multiset<int, greater<int>> s;
    scanf("%d%d", &n, &a[1]);
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &a[i]);
        s.insert(a[i]);
    }
    int ans = 0;
    while (a[1] <= *s.begin()) {
        ++a[1], ++ans;
        s.insert(*s.begin() - 1);
        s.erase(s.begin());
    }
    printf("%d\n", ans);
    return 0;
}
